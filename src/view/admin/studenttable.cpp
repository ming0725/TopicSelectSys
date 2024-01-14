#include "studenttable.h"
#include "ui_infotable.h"
#include "studentinfo.h"
#include "topicinfo.h"
#include "addmember.h"
#include <QMessageBox>
#include <QPushButton>
#include <QScrollBar>

StudentTable::StudentTable(QWidget *parent)
    : InfoTable(parent)
{
    init();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}

QVector<QString> StudentTable::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("学号");
    nameVec.emplace_back("姓名");
    nameVec.emplace_back("性别");
    nameVec.emplace_back("年龄");
    nameVec.emplace_back("系别");
    nameVec.emplace_back("专业");
    nameVec.emplace_back("手机号");
    nameVec.emplace_back("邮箱");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("选题状态");
    nameVec.emplace_back("修改");
    nameVec.emplace_back("操作");
    nameVec.emplace_back("删除");
    return nameVec;
}

static const QMap<QString, QString> priority{
    {"通过", "3"},
    {"审核中", "2"},
    {"不通过", "1"},
    {"未选择", "0"}
};

void StudentTable::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(stuMap.size());

    for (auto& [stuId, stu] : stuMap.toStdMap())
    {
        QString status = selectionMap.count(stuId) ? selectionMap[stuId].getStatus() : "未选择";
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton(status, ui->tableWidget);
        QPushButton* button3 = new QPushButton("修改", ui->tableWidget);
        QPushButton* button4 = new QPushButton("重置密码", ui->tableWidget);
        QPushButton* button5 = new QPushButton("删除", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &StudentTable::onStuInfoBtnClicked);
        connect(button2, &QPushButton::clicked, this, &StudentTable::onStatusBtnClicked);
        connect(button3, &QPushButton::clicked, this, &StudentTable::onModifyBtnClicked);
        connect(button4, &QPushButton::clicked, this, &StudentTable::onResetPwdBtnClicked);
        connect(button5, &QPushButton::clicked, this, &StudentTable::onDelStuBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(stuId);
        QTableWidgetItem* item2 = new QTableWidgetItem(stu.getName());
        QTableWidgetItem* item3 = new QTableWidgetItem(stu.getGender());
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(stu.getAge()));
        QTableWidgetItem* item5 = new QTableWidgetItem(stu.getDepartment());
        QTableWidgetItem* item6 = new QTableWidgetItem(stu.getMajor());
        QTableWidgetItem* item7 = new QTableWidgetItem(stu.getPhone());
        QTableWidgetItem* item8 = new QTableWidgetItem(stu.getEmail());
        QTableWidgetItem* item9 = new QTableWidgetItem(priority[status]);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item3->setTextAlignment(Qt::AlignCenter);
        item4->setTextAlignment(Qt::AlignCenter);
        item5->setTextAlignment(Qt::AlignCenter);
        item6->setTextAlignment(Qt::AlignCenter);
        item9->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, 0, item1);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setItem(row, 9, item9);
        ui->tableWidget->setCellWidget(row, 8, button1);
        ui->tableWidget->setCellWidget(row, 9, button2);
        ui->tableWidget->setCellWidget(row, 10, button3);
        ui->tableWidget->setCellWidget(row, 11, button4);
        ui->tableWidget->setCellWidget(row, 12, button5);
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        button2->setEnabled(priority[status].toInt());
        ++row;
    }
}

void StudentTable::loadData()
{
    stuMap.clear();
    teacherMap.clear();
    topicMap.clear();
    selectionMap.clear();
    auto stuVec = studentModel.queryAll();
    auto teaVec = teacherModel.queryAll();
    auto topicVec = topicModel.queryAll();
    auto seleVec = selectionModel.queryAll();
    for (auto& stu : stuVec)
    {
        stuMap.insert(stu.getId(), stu);
    }
    for (auto& tea : teaVec)
    {
        teacherMap.insert(tea.getId(), tea);
    }
    for (auto& topic : topicVec)
    {
        topicMap.insert(topic.getId(), topic);
    }
    for (auto& sele : seleVec)
    {
        selectionMap.insert(sele.getStudentId(), sele);
    }
}

void StudentTable::onStuInfoBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Information* studentInfo = new StudentInfo(stuMap[stuId]);
        studentInfo->hideAllBtn()->show();
    }
}

void StudentTable::addBtn()
{
    QPushButton *btn = new QPushButton("新增", this);
    btn->setFocusPolicy(Qt::StrongFocus);
    ui->horizontalLayout->addWidget(btn);
    connect(btn,
            &QPushButton::clicked,
            this,
            &StudentTable::onAddStuBtnClicked
    );
}

void StudentTable::onAddStuBtnClicked()
{
    AddMember addMember(AddMember::AddStudent, this);
    if (addMember.exec())
        on_refreshPushButton_clicked();
}

void StudentTable::onStatusBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Selection selection = selectionMap[stuId];
        Topic topic = topicMap[selection.getTopicId()];
        Teacher teacher = teacherMap[topic.getTeacherId()];
        TopicInfo* topicInfo = new TopicInfo(teacher, topic, selection);
        topicInfo->show();
    }
}


void StudentTable::onModifyBtnClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Student &stu = stuMap[stuId];
        Information* studentInfo = new StudentInfo(stu);
        studentInfo->hideModifyPwdBtn()->show();
    }
}


void StudentTable::onDelStuBtnClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    if (clickedBtn)
    {
        auto reply = QMessageBox::information(
                this, "提示", "是否删除该学生？",
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
        );

        if (reply == QMessageBox::Yes)
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString stuId = ui->tableWidget->item(row, 0)->text();
            Student &stu = stuMap[stuId];
            studentModel.remove(stu);
            on_refreshPushButton_clicked();
        }
    }
}

void StudentTable::onResetPwdBtnClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    if (clickedBtn)
    {
        auto reply = QMessageBox::information(
                this, "提示", "是否重置密码？",
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
        );
        if (reply == QMessageBox::Yes)
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString stuId = ui->tableWidget->item(row, 0)->text();
            Student &stu = stuMap[stuId];
            stu.setPassword("123456");
            studentModel.update(stu);
        }
    }
}

void StudentTable::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    static int showWidth = TABLE_WIDGET_COLUMN_WIDTH * ui->tableWidget->columnCount() + TABLE_WIDGET_VERTICAL_HEADER_WIDTH;
    if (size().width() < showWidth)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        {
            ui->tableWidget->setColumnWidth(i ,TABLE_WIDGET_COLUMN_WIDTH);
        }
    }
    else
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}
