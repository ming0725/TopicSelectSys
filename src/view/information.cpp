#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Information)
{
    ui->setupUi(this);
    // 窗口关闭自动释放资源
    setAttribute(Qt::WA_DeleteOnClose);
}

Information::~Information()
{
    delete ui;
}

void Information::on_modifyPushButton_clicked()
{
    // 修改模式开启，可编辑内容
    modifyMode(true);
}

void Information::on_commitPushButton_clicked()
{
    // 提交然后更新数据库
    commit();
    // 修改模式关闭
    modifyMode(false);
    // 重新加载修改后的数据
    loadInfo();
}

void Information::on_cancelPushButton_clicked()
{
    // 修改模式关闭
    modifyMode(false);
    // 恢复显示的数据
    loadInfo();
}

void Information::on_modifyPwdPushButton_clicked()
{
    // 执行修改密码
    modifyPwd();
}

void Information::modifyMode(bool mode)
{
    // 设置提交和取消按钮开启或关闭
    ui->cancelPushButton->setEnabled(mode);
    ui->commitPushButton->setEnabled(mode);
    // 设置输入栏开启关闭
    ui->emailLineEdit   ->setReadOnly(!mode);
    ui->ageLineEdit     ->setReadOnly(!mode);
    ui->nameLineEdit    ->setReadOnly(!mode);
    ui->phoneLineEdit   ->setReadOnly(!mode);
    ui->majorLineEdit   ->setReadOnly(!mode);
    ui->genderLineEdit  ->setReadOnly(!mode);
    ui->deptLineEdit    ->setReadOnly(!mode);
}

Information* Information::init()
{
    loadInfo();
    modifyMode(false);
    return this;
}

Information* Information::hideAllBtn()
{
    ui->cancelPushButton->hide();
    ui->commitPushButton->hide();
    ui->modifyPwdPushButton->hide();
    ui->modifyPushButton->hide();
    return this;
}

Information *Information::hideModifyPwdBtn()
{
    ui->modifyPwdPushButton->hide();
    return this;
}

