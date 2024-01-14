#include "mytopic.h"
#include "ui_infotable.h"
#include "account.h"
#include "modifytopic.h"
#include "topicinfo.h"
#include <QMessageBox>


MyTopic::MyTopic(QWidget *parent)
    : InfoTable(parent)
{
    sortCol = 6;
    order = Qt::SortOrder::DescendingOrder;
    init();
}


QVector<QString> MyTopic::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("题目号");
    nameVec.emplace_back("标题");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("最大选题人数");
    nameVec.emplace_back("剩余量");
    nameVec.emplace_back("修改");
    nameVec.emplace_back("删除");
    return nameVec;
}


void MyTopic::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(topicMap.size());
    for (auto& [topicId, topic] : topicMap.toStdMap())
    {
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("修改", ui->tableWidget);
        QPushButton* button3 = new QPushButton("删除", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &MyTopic::onDetailBtnClicked);
        connect(button2, &QPushButton::clicked, this, &MyTopic::onModifyBtnClicked);
        connect(button3, &QPushButton::clicked, this, &MyTopic::onDeleteBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(topicId);
        QTableWidgetItem* item2 = new QTableWidgetItem(topic.getTitle());
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(topic.getMax()));
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(topic.getMax() - selectCountMap[topicId]));
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 0, item1);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 3, item3);
        ui->tableWidget->setItem(row, 4, item4);
        ui->tableWidget->setCellWidget(row, 2, button1);
        ui->tableWidget->setCellWidget(row, 5, button2);
        ui->tableWidget->setCellWidget(row, 6, button3);
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        ++row;
    }
    sortTable();
}


void MyTopic::loadData()
{
    selectCountMap.clear();
    topicMap.clear();
    selectCountMap = selectionModel.selectCount();
    auto topicVec = topicModel.queryByTeacherId(Account::instance().getId());
    for (auto& topic : topicVec)
    {
        topicMap.insert(topic.getId(), topic);
    }
}


void MyTopic::addBtn()
{
    QPushButton *btn = new QPushButton("新增", this);
    btn->setFocusPolicy(Qt::StrongFocus);
    ui->horizontalLayout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &MyTopic::onAddTopicBtnClicked);
}


void MyTopic::onAddTopicBtnClicked()
{
    ModifyTopic modifyTopic(teacherModel.queryById(Account::instance().getId()));
    modifyTopic.exec();
    on_refreshPushButton_clicked();
}


void MyTopic::onDetailBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Topic& topic = topicMap[topicId];
        Teacher teacher = teacherModel.queryById(topic.getTeacherId());
        TopicInfo* topicInfo = new TopicInfo(teacher, topic);
        topicInfo->show();
    }
}


void MyTopic::onModifyBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        ModifyTopic modifyTopic(topicMap[topicId], this);
        modifyTopic.exec();
        on_refreshPushButton_clicked();
    }
}

void MyTopic::onDeleteBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        auto reply = QMessageBox::information(
                this, "提示", "是否删除该选题？",
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
        );

        if (reply == QMessageBox::Ok)
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString topicId = ui->tableWidget->item(row, 0)->text();
            Teacher teacher = teacherModel.queryById(Account::instance().getId());
            Topic& topic = topicMap[topicId];
            topicModel.remove(topic);
            QMessageBox::information(this, "提示", "删除成功！");
            on_refreshPushButton_clicked();
        }
    }
}
