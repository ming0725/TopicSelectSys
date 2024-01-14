#include "teachertable.h"
#include "ui_infotable.h"
#include "teacherinfo.h"
#include "addmember.h"
#include <QMessageBox>

TeacherTable::TeacherTable(QWidget *parent)
    : InfoTable(parent)
{
    init();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
}


QVector<QString> TeacherTable::setColName()
{
    QVector<QString> nameVec;
    nameVec.emplace_back("学号");
    nameVec.emplace_back("姓名");
    nameVec.emplace_back("性别");
    nameVec.emplace_back("年龄");
    nameVec.emplace_back("系别");
    nameVec.emplace_back("职称");
    nameVec.emplace_back("手机号");
    nameVec.emplace_back("邮箱");
    nameVec.emplace_back("详细");
    nameVec.emplace_back("修改");
    nameVec.emplace_back("操作");
    nameVec.emplace_back("删除");
    return nameVec;
}

void TeacherTable::showData()
{
    int row = 0;
    ui->tableWidget->setRowCount(teacherMap.size());

    for (auto& [teacherId, teacher] : teacherMap.toStdMap())
    {
        QPushButton* button1 = new QPushButton("查看", ui->tableWidget);
        QPushButton* button2 = new QPushButton("修改", ui->tableWidget);
        QPushButton* button3 = new QPushButton("重置密码", ui->tableWidget);
        QPushButton* button4 = new QPushButton("删除", ui->tableWidget);
        connect(button1, &QPushButton::clicked, this, &TeacherTable::onDetailBtnClicked);
        connect(button2, &QPushButton::clicked, this, &TeacherTable::onModifyBtnClicked);
        QTableWidgetItem* item1 = new QTableWidgetItem(teacherId);
        QTableWidgetItem* item2 = new QTableWidgetItem(teacher.getName());
        QTableWidgetItem* item3 = new QTableWidgetItem(teacher.getGender());
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(teacher.getAge()));
        QTableWidgetItem* item5 = new QTableWidgetItem(teacher.getDepartment());
        QTableWidgetItem* item6 = new QTableWidgetItem(teacher.getTitle());
        QTableWidgetItem* item7 = new QTableWidgetItem(teacher.getPhone());
        QTableWidgetItem* item8 = new QTableWidgetItem(teacher.getEmail());
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
        ui->tableWidget->setItem(row, 6, item7);
        ui->tableWidget->setItem(row, 7, item8);
        ui->tableWidget->setCellWidget(row, 8, button1);
        ui->tableWidget->setCellWidget(row, 9, button2);
        ui->tableWidget->setCellWidget(row, 10, button3);
        ui->tableWidget->setCellWidget(row, 11, button4);
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(QString::number(row + 1)));
        ++row;
    }
}

void TeacherTable::loadData()
{
    teacherMap.clear();
    auto teacherVec = teacherModel.queryAll();
    for (auto& teacher : teacherVec)
    {
        teacherMap.insert(teacher.getId(), teacher);
    }
}

void TeacherTable::onDetailBtnClicked()
{
    QPushButton* clickedBtn = qobject_cast<QPushButton*>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString teacherId = ui->tableWidget->item(row, 0)->text();
        Information* teacherInfo = new TeacherInfo(teacherMap[teacherId]);
        teacherInfo->hideAllBtn()->show();
    }
}

void TeacherTable::onModifyBtnClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    if (clickedBtn)
    {
        int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
        QString stuId = ui->tableWidget->item(row, 0)->text();
        Teacher &teacher = teacherMap[stuId];
        Information* teacherInfo = new TeacherInfo(teacher);
        teacherInfo->hideModifyPwdBtn()->show();
    }
}

void TeacherTable::addBtn()
{
    QPushButton *btn = new QPushButton("新增", this);
    btn->setFocusPolicy(Qt::StrongFocus);
    ui->horizontalLayout->addWidget(btn);
    connect(btn,
            &QPushButton::clicked,
            this,
            &TeacherTable::onAddTeaBtnClicked
    );
}

void TeacherTable::onAddTeaBtnClicked()
{
    AddMember addMember(AddMember::AddTeacher, this);
    if (addMember.exec())
        on_refreshPushButton_clicked();
}

void TeacherTable::onDelTeaBtnClicked()
{
    QPushButton *clickedBtn = qobject_cast<QPushButton *>(sender());
    if (clickedBtn)
    {
        auto reply = QMessageBox::information(
                this, "提示", "是否删除该教师？",
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No)
        );
        if (reply == QMessageBox::Yes)
        {
            int row = ui->tableWidget->indexAt(clickedBtn->pos()).row();
            QString teacherId = ui->tableWidget->item(row, 0)->text();
            Teacher &teacher = teacherMap[teacherId];
            teacherModel.remove(teacher);
            on_refreshPushButton_clicked();
        }
    }
}

void TeacherTable::onResetPwdBtnClicked()
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
            QString teacherId = ui->tableWidget->item(row, 0)->text();
            Teacher &teacher = teacherMap[teacherId];
            teacher.setPassword("123456");
            teacherModel.update(teacher);
            on_refreshPushButton_clicked();
        }
    }
}


void TeacherTable::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    static int criticalWidth = TABLE_WIDGET_COLUMN_WIDTH * ui->tableWidget->columnCount() + TABLE_WIDGET_VERTICAL_HEADER_WIDTH;
    if (size().width() < criticalWidth)
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
