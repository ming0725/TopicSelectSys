#include "adminclient.h"
#include "ui_client.h"
#include "studenttable.h"
#include "teachertable.h"
#include "topictable.h"
#include "admininfo.h"
#include "account.h"

AdminClient::AdminClient(QWidget *parent)
    : Client(parent)
{
    init();
}

QString AdminClient::getClientTitle()
{
    return QString("管理员端");
}

QString AdminClient::getUserTitle()
{
    return QString("您好，尊贵的%1老大").arg(Account::instance().getName());
}

void AdminClient::addTreeItems(QTreeWidgetItem *root)
{
    root->addChild(new QTreeWidgetItem(root, QStringList("个人信息")));
    root->addChild(new QTreeWidgetItem(root, QStringList("学生管理")));
    root->addChild(new QTreeWidgetItem(root, QStringList("教师管理")));
    root->addChild(new QTreeWidgetItem(root, QStringList("选题管理")));
}

void AdminClient::addWidgets()
{
    ui->stackedWidget->addWidget(new AdminInfo(this));
    ui->stackedWidget->addWidget(new StudentTable(this));
    ui->stackedWidget->addWidget(new TeacherTable(this));
    ui->stackedWidget->addWidget(new TopicTable(this));
}
