#include "studentclient.h"
#include "account.h"
#include "studentinfo.h"
#include "teacherinfo.h"
#include "selecttopic.h"
#include "topicinfo.h"
#include "selectionmodel.h"
#include "ui_client.h"

StudentClient::StudentClient(QWidget *parent)
    : Client(parent)
{
    init();
}

QString StudentClient::getClientTitle()
{
    return QString("学生端");
}

QString StudentClient::getUserTitle()
{
    return QString("您好，%1大王").arg(Account::instance().getName());
}

void StudentClient::addTreeItems(QTreeWidgetItem *root)
{
    root->addChild(new QTreeWidgetItem(root, QStringList("个人信息")));
    root->addChild(new QTreeWidgetItem(root, QStringList("进入选题")));
    root->addChild(new QTreeWidgetItem(root, QStringList("我的选题")));
    root->addChild(new QTreeWidgetItem(root, QStringList("我的导师")));
}

void StudentClient::addWidgets()
{
    ui->stackedWidget->addWidget(new StudentInfo(this));
    ui->stackedWidget->addWidget(new SelectTopic(this));
    ui->stackedWidget->addWidget(new TopicInfo(Account::instance().getId(), this));
    ui->stackedWidget->addWidget((new TeacherInfo(Account::instance().getId(), this))->hideAllBtn());
    auto selectTopic = static_cast<SelectTopic*>(ui->stackedWidget->widget(1));
    auto topicInfo = static_cast<TopicInfo*>(ui->stackedWidget->widget(2));
    auto teacherInfo = static_cast<TeacherInfo*>(ui->stackedWidget->widget(3));
    connect(selectTopic, &SelectTopic::dataUpdate, topicInfo, &TopicInfo::stuChangeTopic);
    connect(selectTopic, &SelectTopic::dataUpdate, teacherInfo, &TeacherInfo::stuChangeTopic);
}
