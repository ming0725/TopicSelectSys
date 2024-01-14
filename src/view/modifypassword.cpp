#include "modifypassword.h"
#include "ui_modifypassword.h"
#include "studentmodel.h"
#include "teachermodel.h"
#include "adminmodel.h"
#include <QMessageBox>
#include <QException>

ModifyPassword::ModifyPassword(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::ModifyPassword)
{
    ui->setupUi(this);
}

ModifyPassword::~ModifyPassword()
{
    delete ui;
}

ModifyPassword::ModifyPassword(Student &student, QDialog *parent)
    : ModifyPassword(parent)
{
    this->student = student;
    oldPwd = student.getPassword();
    callback = std::bind(&ModifyPassword::modifyStudentPwd, this, std::placeholders::_1);
}

ModifyPassword::ModifyPassword(Teacher &teacher, QDialog *parent)
    : ModifyPassword(parent)
{
    this->teacher = teacher;
    oldPwd = teacher.getPassword();
    callback = std::bind(&ModifyPassword::modifyTeacherPwd, this, std::placeholders::_1);
}

ModifyPassword::ModifyPassword(Admin &admin, QDialog *parent)
    : ModifyPassword(parent)
{
    this->admin = admin;
    oldPwd = admin.getPassword();
    callback = std::bind(&ModifyPassword::modifyAdminPwd, this, std::placeholders::_1);
}

void ModifyPassword::on_commitPushButton_clicked()
{
    if (ui->oldPwdLineEdit->text().isEmpty()
        || ui->newPwdLineEdit->text().isEmpty()
        || ui->confirmPwdLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "提示", "密码不能为空！");
    }
    else if (ui->confirmPwdLineEdit->text() != ui->newPwdLineEdit->text())
    {
        QMessageBox::warning(this, "提示", "两次密码不一致！");
    }
    else if (ui->oldPwdLineEdit->text() != oldPwd)
    {
        QMessageBox::warning(this, "提示", "旧密码不一致！");
    }
    else
    {
        try
        {
            QString&& newPwd = ui->newPwdLineEdit->text();
            callback(newPwd);
            QMessageBox::information(this, "提示", "修改成功！");
            accept();
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


void ModifyPassword::on_cancelPushButton_clicked()
{
    reject();
}


void ModifyPassword::modifyStudentPwd(QString &newPwd)
{
    student.setPassword(newPwd);
    StudentModel().update(student);
}


void ModifyPassword::modifyTeacherPwd(QString &newPwd)
{
    teacher.setPassword(newPwd);
    TeacherModel().update(teacher);
}


void ModifyPassword::modifyAdminPwd(QString &newPwd)
{
    admin.setPassword(newPwd);
    AdminModel().update(admin);
}
