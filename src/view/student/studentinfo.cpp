#include "studentinfo.h"
#include "ui_information.h"
#include "account.h"
#include "modifypassword.h"
#include <QMessageBox>
#include <QException>

StudentInfo::StudentInfo(QWidget *parent)
    : Information(parent)
{
    self = studentModel.queryById(Account::instance().getId());
    init();
}

StudentInfo::StudentInfo(QString stuId, QWidget *parent)
    : Information(parent)
{
    self = studentModel.queryById(stuId);
    init();
}

StudentInfo::StudentInfo(Student stu, QWidget *parent)
    : Information(parent)
{
    self = stu;
    init();
}

void StudentInfo::commit()
{
    Student temp = self;
    self.setAge(ui->ageLineEdit->text().toInt());
    self.setDepartment(ui->deptLineEdit->text());
    self.setEmail(ui->emailLineEdit->text());
    self.setGender(ui->genderLineEdit->text());
    self.setMajor(ui->majorLineEdit->text());
    self.setName(ui->nameLineEdit->text());
    self.setPhone(ui->phoneLineEdit->text());
    try
    {
        studentModel.update(self);
    }
    catch (const QException& e)
    {
        QMessageBox::warning(this, "错误", e.what());
        self = temp;
        loadInfo();
    }
    catch (...)
    {
        QMessageBox::warning(this, "提示", "未知错误！");
    }
}

void StudentInfo::modifyPwd()
{
    ModifyPassword modifyPassword(self);
    modifyPassword.exec();
    self = studentModel.queryById(Account::instance().getId());
}

void StudentInfo::loadInfo()
{
    ui->ageLineEdit   ->setText(QString::number(self.getAge()));
    ui->deptLineEdit  ->setText(self.getDepartment());
    ui->emailLineEdit ->setText(self.getEmail());
    ui->majorLineEdit ->setText(self.getMajor());
    ui->nameLineEdit  ->setText(self.getName());
    ui->phoneLineEdit ->setText(self.getPhone());
    ui->stuidLineEdit ->setText(self.getId());
    ui->genderLineEdit->setText(self.getGender());
}
