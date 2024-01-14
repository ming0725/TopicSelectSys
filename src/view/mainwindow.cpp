#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "studentmodel.h"
#include "teachermodel.h"
#include "adminmodel.h"
#include "studentclient.h"
#include "teacherclient.h"
#include "adminclient.h"
#include "account.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置窗口图标
    setWindowIcon(QIcon(":/icon.jpg"));
    // 窗口固定大小为1280x720
    setFixedSize(1280, 720);
    // 少了这行代码登录界面会显示不全 我也不知道为什么
    ui->centralwidget->setFixedSize(width(), height());
    // 账号输入栏设置焦点
    ui->accountLineEdit->setFocus();

    // 设置背景图片
    QPixmap pixmap(":/background.jpg");
    QPalette palette;
    pixmap = pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, pixmap);
    // 背景自动填充
    setAutoFillBackground(true);
    setPalette(palette);

    // 居中显示
    int x = (this->width()  - ui->frame->width())  >> 1;
    int y = (this->height() - ui->frame->height()) >> 1;
    ui->frame->setGeometry(x, y + 50, ui->frame->width(), ui->frame->height());

    // 连接槽函数，在输入密码完密码按下回车后直接执行按下登录键的函数
    connect(ui->pwdLineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_loginBtn_clicked);
    // 登录验证成功后发出succ信号，使用lambda函数执行登录成功后的操作
    connect(this, &MainWindow::succ, this, [this](Client* client){
        // 显示客户端
        client->show();
        // 登录窗口隐藏
        this->hide();
        this->client = client;
        // 客户端关闭后执行
        connect(client, &Client::destroyed, this, [this](){
            // 客户端关闭后显示登录界面
            this->show();
        });
    });

    // 登录失败后发射fail信号
    connect(this, &MainWindow::fail, this, [this](){
        // 提示密码错误
        QMessageBox::warning(this, "提示", "密码错误！");
        // 密码输入栏清空
        ui->pwdLineEdit->clear();
    });

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginBtn_clicked()
{
    // 根据账号和密码栏获取输入的字符串
    QString id = ui->accountLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();

    // 获取到Account单例，设置id和name
    auto& accout = Account::instance();
    accout.setId(id);
    // 输入为空的提示
    if (id.isEmpty() || pwd.isEmpty())
    {
        QMessageBox::warning(this, "提示", "账号或密码不能为空！");
        return;
    }

    // 勾选学生登录
    if (ui->stuRadioButton->isChecked())
    {
        // 使用学生model查询数据库
        StudentModel stuModel;
        Student stu = stuModel.queryById(id);
        // 判断密码是否正确
        if (pwd == stu.getPassword())
        {
            // 设置Account name
            accout.setName(stu.getName());
            // 发射登录成功信号，创建学生客户端
            emit succ(new StudentClient());
        }
        else
            // 验证失败，发射失败信号
            emit fail();
    }
    // 勾选教师登录
    else if (ui->teaRadioButton->isChecked())
    {
        // 使用教师model查询数据库
        TeacherModel teacherModel;
        Teacher teacher = teacherModel.queryById(id);
        if (pwd == teacher.getPassword())
        {
            // 设置Account name
            accout.setName(teacher.getName());
            // 发射登录成功信号，创建教师客户端
            emit succ(new TeacherClient());
        }
        else
            // 验证失败，发射失败信号
            emit fail();
    }
    // 勾选管理员登录
    else
    {
        // 使用管理员model查询数据库
        AdminModel adminModel;
        Admin admin = adminModel.queryById(id);
        if (pwd == admin.getPassword())
        {
            // 设置Account name
            accout.setName(admin.getName());
            // 发射登录成功信号，创建管理员客户端
            emit succ(new AdminClient());
        }
        else
            // 验证失败，发射失败信号
            emit fail();
    }
}


void MainWindow::on_exitBtn_clicked()
{
    // 按下退出按钮直接关闭程序
    exit(0);
}

