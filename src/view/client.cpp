#include "client.h"
#include "ui_client.h"

#include <QGuiApplication>
#include <QScreen>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    // 设置窗口大小
    resize(1000, 500);
    // 设置客户端图标
    setWindowIcon(QIcon(":/icon.jpg"));

    /// 居中显示
    QRect availableGeometry = QGuiApplication::primaryScreen()->availableGeometry();
    int x = (availableGeometry.width()  - width())  >> 1;
    int y = (availableGeometry.height() - height()) >> 1;
    move(x, y);
}

Client::~Client()
{
    delete ui;
}

void Client::init()
{
    // 窗口关闭自动释放内存
    setAttribute(Qt::WA_DeleteOnClose);
    // 设置客户端标题
    ui->clientTitle->setText(getClientTitle());
    // 设置窗口标题
    setWindowTitle("毕业选题系统-" + getClientTitle());
    // 设置用户称呼
    ui->userTitle->setText(getUserTitle());
    // 菜单栏添加根目录
    auto root = new QTreeWidgetItem(ui->treeWidget, QStringList(">菜单"));
    // 在根目录中添加子选项
    addTreeItems(root);
    // 添加点击菜单选项后显示的子窗口
    addWidgets();
    // 默认展开所有选项
    root->setExpanded(true);

    // 设置显示的子窗口
    ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(0));
    // 选项被点击
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, [this, root](QTreeWidgetItem *item){
        // 被点击在选项中的索引
        int index = root->indexOfChild(item);
        // 点击为子选项时则切换子窗口
        if (index > -1)
            ui->stackedWidget->setCurrentIndex(index);
    });
}


void Client::on_exitPushButton_clicked()
{
    // 按下退出直接退出程序
    // 需要返回登录界面要点击右上角X号
    exit(0);
}

