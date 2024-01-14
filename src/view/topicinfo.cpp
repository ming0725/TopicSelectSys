#include "topicinfo.h"
#include "ui_topicinfo.h"
#include "selectionmodel.h"
#include "topicmodel.h"
#include "teachermodel.h"

TopicInfo::TopicInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TopicInfo)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

TopicInfo::TopicInfo(QString stuId, QWidget *parent)
    : TopicInfo(parent)
{
    QString tea_id = SelectionModel().querySelectedTeacherIdByStuId(stuId);
    Teacher teacher = TeacherModel().queryById(tea_id);
    Selection selection = SelectionModel().queryById(stuId);
    Topic topic = TopicModel().queryById(selection.getTopicId());
    setTeacherTopicInfo(teacher, topic);
    ui->statusLineEdit->setText(selection.getStatus());
}

TopicInfo::TopicInfo(Teacher &teacher, Topic &topic, Selection &selection, QWidget *parent)
    : TopicInfo(parent)
{
    setTeacherTopicInfo(teacher, topic);
    ui->statusLineEdit->setText(selection.getStatus());
}

TopicInfo::TopicInfo(Teacher &teacher, Topic &topic, QWidget *parent)
    : TopicInfo(parent)
{
    setTeacherTopicInfo(teacher, topic);
    ui->statusLineEdit->hide();
    ui->statusLabel->hide();
}


TopicInfo::~TopicInfo()
{
    delete ui;
}

void TopicInfo::setTeacherTopicInfo(Teacher &teacher, Topic &topic)
{
    ui->tpidLineEdit->setText(topic.getId());
    ui->teaidLineEdit->setText(teacher.getId());
    ui->teaLineEdit->setText(teacher.getName());
    ui->titleLineEdit->setText(topic.getTitle());
    ui->descTextEdit->setText(topic.getDesc());
    ui->reqTextEdit->setText(topic.getRequirement());
}

void TopicInfo::stuChangeTopic(Teacher teacher, Topic topic, Selection selection)
{
    setTeacherTopicInfo(teacher, topic);
    ui->statusLineEdit->setText(selection.getStatus());
}
