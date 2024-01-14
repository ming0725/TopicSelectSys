#include "admininfo.h"
#include "account.h"
#include "ui_information.h"
#include "modifypassword.h"
#include <QException>
#include <QMessageBox>

AdminInfo::AdminInfo(QWidget *parent)
    : Information(parent)
{
    self = adminModel.queryById(Account::instance().getId());
    init();
}

void AdminInfo::commit()
{
    Admin temp = self;
    self.setName (ui->nameLineEdit ->text());
    self.setPhone(ui->phoneLineEdit->text());
    self.setId   (ui->stuidLineEdit->text());
    try
    {
        if (self.getId() != temp.getId())
            adminModel.updateId(temp, self.getId());
        adminModel.update(self);
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

void AdminInfo::modifyPwd()
{
    ModifyPassword modifyPassword(self);
    modifyPassword.exec();
}

void AdminInfo::loadInfo()
{
    ui->stuidLabel   ->setText("账号");
    ui->stuidLineEdit->setText(self.getId());
    ui->nameLineEdit ->setText(self.getName());
    ui->phoneLineEdit->setText(self.getPhone());
    ui->genderLineEdit->clear();
    ui->majorLineEdit->clear();
    ui->emailLineEdit->clear();
}
