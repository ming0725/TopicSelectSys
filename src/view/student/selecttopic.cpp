#include "selecttopic.h"
#include "ui_infotable.h"
#include "teacherinfo.h"
#include "account.h"
#include "topicinfo.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QException>

SelectTopic::SelectTopic(QWidget *parent)
    : InfoTable(parent)
{
    sortCol = 6;
    order = Qt::SortOrder::DescendingOrder;
    init();
}


QVector<QString> SelectTopic::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("题目号");
    nameVec.emplace_back("出题教师");
    nameVec.emplace_back("教师信息");
    nameVec.emplace_back("标题");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("最大选题人数");
    nameVec.emplace_back("剩余量");
    nameVec.emplace_back("选择");
    return nameVec;
}


void SelectTopic::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(topicMap.size());
    for (auto& [topicId, topic] : topicMap.toStdMap())
    {
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button3 = new QPushButton("选择", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &SelectTopic::onTeaInfoButtonClicked);
        connect(button2, &QPushButton::clicked, this, &SelectTopic::onTopicInfoButtonClicked);
        connect(button3, &QPushButton::clicked, this, &SelectTopic::onSelectButtonClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(topicId);
        QTableWidgetItem* item2 = new QTableWidgetItem(teacherMap[topic.getTeacherId()].getName());
        QTableWidgetItem* item3 = new QTableWidgetItem(topic.getTitle());
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
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        button3->setEnabled("0" != item5->text());
        ++row;
    }
    auto items = ui->tableWidget->findItems(mySelection.getTopicId(), Qt::MatchExactly);
    for (auto& item : items)
    {
        ui->tableWidget->cellWidget(item->row(), 7)->setEnabled(false);
        auto btn = qobject_cast<QPushButton*>(ui->tableWidget->cellWidget(item->row(), 7));
        btn->setText(mySelection.getStatus());
    }
    sortTable();
}


void SelectTopic::loadData()
{
    teacherMap.clear();
    selectCountMap.clear();
    selectCountMap = selectionModel.selectCount();
    mySelection = selectionModel.queryById(Account::instance().getId());
    auto topicVec = topicModel.queryAll();
    auto teacherVec = teacherModel.queryAll();
    for (auto& teacher: teacherVec)
    {
        teacherMap.insert(teacher.getId(), teacher);
    }
    for (auto& topic : topicVec)
    {
        topicMap.insert(topic.getId(), topic);
    }
}


void SelectTopic::onTeaInfoButtonClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Teacher& teacher = teacherMap[topicMap[topicId].getTeacherId()];
        Information* teacherInfo = new TeacherInfo(teacher);
        teacherInfo->hideAllBtn()->show();
    }
}


void SelectTopic::onTopicInfoButtonClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString topicId = ui->tableWidget->item(row, 0)->text();
        Teacher& teacher = teacherMap[topicMap[topicId].getTeacherId()];
        Topic& topic = topicMap[topicId];
        TopicInfo* topicInfo = new TopicInfo(teacher, topic);
        topicInfo->show();
    }
}


void SelectTopic::onSelectButtonClicked()
{
    if (mySelection.getStatus() == "通过")
    {
        QMessageBox::information(this, "提示", "您的选题已通过，无法修改");
        return;
    }
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    try
    {
        if (clickedBtn && mySelection.getStatus() == "审核中")
        {
            auto reply = QMessageBox::information(
                    this, "提示", "是否修改为该选题？",
                    QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
            );
            if (reply == QMessageBox::Yes)
            {
                int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
                QString topicId = ui->tableWidget->item(row, 0)->text();
                Selection selection;
                selection.setTopicId(topicId);
                selection.setStudentId(mySelection.getStudentId());
                selection.setStatus("审核中");
                selectionModel.update(selection);
                QMessageBox::information(this, "提示", "修改成功！");
                emit dataUpdate(teacherMap[topicMap[topicId].getTeacherId()], topicMap[topicId], selection);
            }
        }
        else if (clickedBtn && mySelection.getStatus() == "不通过")
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString topicId = ui->tableWidget->item(row, 0)->text();
            Selection selection;
            selection.setTopicId(topicId);
            selection.setStudentId(mySelection.getStudentId());
            selection.setStatus("审核中");
            selectionModel.update(selection);
            QMessageBox::information(this, "提示", "选择成功！");
            emit dataUpdate(teacherMap[topicMap[topicId].getTeacherId()], topicMap[topicId], selection);
        }
        else if (clickedBtn && mySelection.getStatus().isEmpty())
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString topicId = ui->tableWidget->item(row, 0)->text();
            Selection selection;
            selection.setTopicId(topicId);
            selection.setStudentId(Account::instance().getId());
            selection.setStatus("审核中");
            selectionModel.insert(selection);
            QMessageBox::information(this, "提示", "选择成功！");
            emit dataUpdate(teacherMap[topicMap[topicId].getTeacherId()], topicMap[topicId], selection);
        }
        on_refreshPushButton_clicked();
    } // try
    catch (const QException& e)
    {
        QMessageBox::warning(this, "提示", e.what());
    } // catch
    catch (...)
    {
        QMessageBox::warning(this, "提示", "未知错误！");
    }
} // onSelectButtonClicked
