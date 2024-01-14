#include "addmember.h"
#include "ui_addmember.h"
#include <QException>
#include <QMessageBox>

#define DEFAULT_PASSWORD "123456"
AddMember::AddMember(Mode mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);
    if (mode == AddStudent)
    {
        callback = [this](){
            Student student;
            student.setId(ui->stuidLineEdit->text());
            student.setName(ui->nameLineEdit->text());
            student.setMajor(ui->majorLineEdit->text());
            student.setDepartment(ui->deptLineEdit->text());
            student.setPhone(ui->phoneLineEdit->text());
            student.setGender(ui->genderComboBox->currentText());
            student.setAge(ui->ageLineEdit->text().toInt());
            student.setPassword(DEFAULT_PASSWORD);
            studentModel.insert(student);
        };
    }
    else if (mode == AddTeacher)
    {
        ui->majorLable->setText("职称");
        callback = [this](){
            Teacher teacher;
            teacher.setId(ui->stuidLineEdit->text());
            teacher.setName(ui->nameLineEdit->text());
            teacher.setTitle(ui->majorLineEdit->text());
            teacher.setDepartment(ui->deptLineEdit->text());
            teacher.setPhone(ui->phoneLineEdit->text());
            teacher.setGender(ui->genderComboBox->currentText());
            teacher.setAge(ui->ageLineEdit->text().toInt());
            teacher.setPassword(DEFAULT_PASSWORD);
            teacherModel.insert(teacher);
        };
    }
}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_commitPushButton_clicked()
{
    try
    {
        callback();
        QMessageBox::information(this, "提示", "添加成功");
        accept();
    }
    catch (const QException& e)
    {
        QMessageBox::warning(this, "提示", e.what());
    }
    catch (...)
    {
        QMessageBox::warning(this, "提示", "未知错误");
    }
}

void AddMember::on_cancelPushButton_clicked()
{
    reject();
}
