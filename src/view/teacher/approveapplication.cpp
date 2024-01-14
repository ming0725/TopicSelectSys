#include "approveapplication.h"
#include "account.h"
#include "ui_infotable.h"
#include "studentinfo.h"
#include <QDialog>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QLabel>

ApproveApplication::ApproveApplication(QWidget *parent)
    : InfoTable(parent)
{
    self = TeacherModel().queryById(Account::instance().getId());
    init();
}

QVector<QString> ApproveApplication::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("学号");
    nameVec.emplace_back("姓名");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("题目号");
    nameVec.emplace_back("标题");
    nameVec.emplace_back("审核");
    return nameVec;
}

void ApproveApplication::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(stuTopicMap.size());
    for (auto& [stuId, stuTopic] : stuTopicMap.toStdMap())
    {
        auto& stu = stuTopic.first;
        auto& topic = stuTopic.second;
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("审核", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &ApproveApplication::onTopicInfoBtnClicked);
        connect(button2, &QPushButton::clicked, this, &ApproveApplication::onValidBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(stuId);
        QTableWidgetItem* item2 = new QTableWidgetItem(stu.getName());
        QTableWidgetItem* item3 = new QTableWidgetItem(topic.getId());
        QTableWidgetItem* item4 = new QTableWidgetItem(topic.getTitle());
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
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        ++row;
    }
}

void ApproveApplication::loadData()
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

ApproveApplication::ApproveApplication(QString id, QWidget *parent)
    : InfoTable(parent)
{
    self = TeacherModel().queryById(id);
}

void ApproveApplication::onTopicInfoBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        StudentInfo* studentInfo = new StudentInfo(stuId);
        studentInfo->hideAllBtn()->show();
    }
}

void ApproveApplication::onValidBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        QString topicId = ui->tableWidget->item(row, 3)->text();
        Selection selection;
        selection.setStudentId(stuId);
        selection.setTopicId(topicId);
        QDialog* dialog = new QDialog(this);
        dialog->setWindowModality(Qt::WindowModal);
        dialog->setWindowTitle("提示");
        QLabel* textLabel = new QLabel("是否通过？", dialog);
        textLabel->setAlignment(Qt::AlignCenter);
        QPushButton *acceptBtn = new QPushButton("通过", dialog);
        QPushButton *rejectBtn = new QPushButton("不通过", dialog);
        QPushButton *cancelBtn = new QPushButton("取消", dialog);
        connect(acceptBtn, &QPushButton::clicked, dialog,
        [this, selection, dialog]() mutable
        {
            selection.setStatus("通过");
            this->selectionModel.update(selection);
            dialog->close();
        });

        connect(rejectBtn, &QPushButton::clicked, dialog,
    [this, selection, dialog]() mutable
        {
            selection.setStatus("不通过");
            this->selectionModel.update(selection);
            dialog->close();
        });
        connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::close);
        QDialogButtonBox *buttonBox = new QDialogButtonBox(dialog);
        buttonBox->addButton(acceptBtn, QDialogButtonBox::ButtonRole::AcceptRole);
        buttonBox->addButton(rejectBtn, QDialogButtonBox::ButtonRole::RejectRole);
        buttonBox->addButton(cancelBtn, QDialogButtonBox::ButtonRole::RejectRole);
        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(textLabel);
        layout->addWidget(buttonBox);
        dialog->exec();
        on_refreshPushButton_clicked();
    }
}
