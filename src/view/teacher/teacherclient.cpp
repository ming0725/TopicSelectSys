#include "teacherclient.h"
#include "ui_client.h"
#include "account.h"
#include "teacherinfo.h"
#include "studenttable.h"
#include "mystudent.h"
#include "mytopic.h"
#include "approveapplication.h"

TeacherClient::TeacherClient()
{
    init();
}

QString TeacherClient::getClientTitle()
{
    return QString("教师端");
}

QString TeacherClient::getUserTitle()
{
    return QString("您好，%1老师").arg(Account::instance().getName());
}

void TeacherClient::addTreeItems(QTreeWidgetItem *root)
{
    root->addChild(new QTreeWidgetItem(root, QStringList("个人信息")));
    root->addChild(new QTreeWidgetItem(root, QStringList("审核申请")));
    root->addChild(new QTreeWidgetItem(root, QStringList("我的题目")));
    root->addChild(new QTreeWidgetItem(root, QStringList("我的学生")));
}

void TeacherClient::addWidgets()
{
    ui->stackedWidget->addWidget(new TeacherInfo(this));
    ui->stackedWidget->addWidget(new ApproveApplication(this));
    ui->stackedWidget->addWidget(new MyTopic(this));
    ui->stackedWidget->addWidget(new MyStudent(this));
}
