#include "topictable.h"
#include "ui_infotable.h"
#include "topicinfo.h"
#include "teacherinfo.h"
#include "modifytopic.h"
#include <QException>
#include <QMessageBox>

TopicTable::TopicTable(QWidget *parent)
    : InfoTable(parent)
{
    init();
}


QVector<QString> TopicTable::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("题目号");
    nameVec.emplace_back("标题");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("出题教师");
    nameVec.emplace_back("教师信息");
    nameVec.emplace_back("最大选题人数");
    nameVec.emplace_back("剩余量");
    nameVec.emplace_back("修改");
    nameVec.emplace_back("删除");
    return nameVec;
}


void TopicTable::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(topicMap.size());
    for (auto& [topicId, topic] : topicMap.toStdMap())
    {
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button3 = new QPushButton("修改", ui->tableWidget);
        QPushButton* button4 = new QPushButton("删除", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &TopicTable::onTopicDetailBtnClicked);
        connect(button2, &QPushButton::clicked, this, &TopicTable::onTeachDetailBtnClicked);
        connect(button3, &QPushButton::clicked, this, &TopicTable::onModifyBtnClicked);
        connect(button4, &QPushButton::clicked, this, &TopicTable::onDeleteBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(topicId);
        QTableWidgetItem* item2 = new QTableWidgetItem(topic.getTitle());
        QTableWidgetItem* item3 = new QTableWidgetItem(teacherMap[topic.getTeacherId()].getName());
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(topic.getMax()));
        QTableWidgetItem* item5 = new QTableWidgetItem(QString::number(topic.getMax() - selectCountMap[topicId]));
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 0, item1);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 3, item3);
        ui->tableWidget->setItem(row, 5, item4);
        ui->tableWidget->setItem(row, 6, item5);
        ui->tableWidget->setCellWidget(row, 2, button1);
        ui->tableWidget->setCellWidget(row, 4, button2);
        ui->tableWidget->setCellWidget(row, 7, button3);
        ui->tableWidget->setCellWidget(row, 8, button4);
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        ++row;
    }
}


void TopicTable::loadData()
{
    topicMap.clear();
    teacherMap.clear();
    selectCountMap.clear();
    auto topicVec = topicModel.queryAll();
    auto teachVec = teacherModel.queryAll();
    selectCountMap = selectionModel.selectCount();
    for (auto& topic : topicVec)
    {
        topicMap.insert(topic.getId(), topic);
    }
    for (auto& teacher : teachVec)
    {
        teacherMap.insert(teacher.getId(), teacher);
    }
}


void TopicTable::onModifyBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Topic &topic = topicMap[topicId];
        ModifyTopic modifyTopic(topic);
        modifyTopic.exec();
    }
}


void TopicTable::onDeleteBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        auto reply = QMessageBox::information(
                this, "提示", "是否删除该选题？",
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
        );
        if (reply == QMessageBox::Yes)
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString topicId = ui->tableWidget->item(row, 0)->text();
            Topic& topic = topicMap[topicId];
            try
            {
                topicModel.remove(topic);
                QMessageBox::information(this, "提示", "删除成功!");
            }
            catch (const QException& e)
            {
                QMessageBox::warning(this, "提示", e.what());
            }
            catch (...)
            {
                QMessageBox::warning(this, "提示", "未知错误！");
            }
        }
    }
}

void TopicTable::onTeachDetailBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Topic &topic = topicMap[topicId];
        Teacher &teacher = teacherMap[topic.getTeacherId()];
        TeacherInfo* teacherInfo = new TeacherInfo(teacher);
        teacherInfo->hideAllBtn()->show();
    }
}


void TopicTable::onTopicDetailBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Topic &topic = topicMap[topicId];
        Teacher &teacher = teacherMap[topic.getTeacherId()];
        TopicInfo* topicInfo = new TopicInfo(teacher, topic);
        topicInfo->show();
    }
}
