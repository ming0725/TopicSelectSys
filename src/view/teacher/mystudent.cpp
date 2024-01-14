#include "mystudent.h"
#include "account.h"
#include "ui_infotable.h"
#include "studentinfo.h"
#include "topicinfo.h"
#include <QPushButton>

MyStudent::MyStudent(QWidget *parent)
    : InfoTable(parent) { init(); }

QVector<QString> MyStudent::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("学号");
    nameVec.emplace_back("姓名");
    nameVec.emplace_back("性别");
    nameVec.emplace_back("年龄");
    nameVec.emplace_back("系别");
    nameVec.emplace_back("专业");
    nameVec.emplace_back("选题");
    nameVec.emplace_back("详细");
    return nameVec;
}


void MyStudent::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(stuTopicMap.size());
    for (auto& [stuId, stuTopic] : stuTopicMap.toStdMap())
    {
        auto& stu = stuTopic.first;
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("查看", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &MyStudent::onTopicInfoBtnClicked);
        connect(button2, &QPushButton::clicked, this, &MyStudent::onStuInfoBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(stuId);
        QTableWidgetItem* item2 = new QTableWidgetItem(stu.getName());
        QTableWidgetItem* item3 = new QTableWidgetItem(stu.getGender());
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(stu.getAge()));
        QTableWidgetItem* item5 = new QTableWidgetItem(stu.getDepartment());
        QTableWidgetItem* item6 = new QTableWidgetItem(stu.getMajor());
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item6->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 0, item1);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setCellWidget(row, 6, button1);
        ui->tableWidget->setCellWidget(row, 7, button2);
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        ++row;
    }
}


void MyStudent::loadData()
{
    stuTopicMap.clear();
    selectVec.clear();
    QString status = "通过";
    selectVec = selectionModel.queryByTeaIdAndStatus(Account::instance().getId(), status);
    for (auto& selection : selectVec)
    {
        auto topic = topicModel.queryById(selection.getTopicId());
        auto stu = studentModel.queryById(selection.getStudentId());
        stuTopicMap.insert(stu.getId(), {stu, topic});
    }
}


void MyStudent::onStuInfoBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Information* studentInfo = new StudentInfo(stuTopicMap[stuId].first);
        studentInfo->hideAllBtn()->show();
    }
}


void MyStudent::onTopicInfoBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Teacher teacher = teacherModel.queryById(Account::instance().getId());
        Topic &topic = stuTopicMap[stuId].second;
        Selection selection;
        selection.setStatus("通过");
        TopicInfo* topicInfo = new TopicInfo(teacher, topic, selection);
        topicInfo->show();
    }
}
