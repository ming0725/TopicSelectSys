#include "teacherinfo.h"
#include "ui_information.h"
#include "modifypassword.h"
#include "selectionmodel.h"
#include "account.h"
#include <QMessageBox>
#include <QException>

TeacherInfo::TeacherInfo(QWidget *parent)
    : Information(parent)
{
    self = teacherModel.queryById(Account::instance().getId());
    init();
}

TeacherInfo::TeacherInfo(Teacher teacher, QWidget *parent)
    : Information(parent)
    , self(teacher)
{
    init();
}

TeacherInfo::TeacherInfo(QString stuId, QWidget *parent)
    : Information(parent)
{
    QString tea_id = SelectionModel().querySelectedTeacherIdByStuId(stuId);
    Teacher teacher = TeacherModel().queryById(tea_id);
    self = teacher;
    init();
}

void TeacherInfo::commit()
{
    Teacher temp = self;
    self.setAge(ui->ageLineEdit->text().toInt());
    self.setDepartment(ui->deptLineEdit->text());
    self.setEmail(ui->emailLineEdit->text());
    self.setGender(ui->genderLineEdit->text());
    self.setTitle(ui->majorLineEdit->text());
    self.setName(ui->nameLineEdit->text());
    self.setPhone(ui->phoneLineEdit->text());
    try
    {
        teacherModel.update(self);
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

void TeacherInfo::modifyPwd()
{
    ModifyPassword modifyPassword(self);
    modifyPassword.exec();
    self = teacherModel.queryById(Account::instance().getId());
}

void TeacherInfo::loadInfo()
{
    ui->majorLable    ->setText("职称");
    ui->stuidLabel    ->setText("账号");
    ui->stuidLineEdit ->setText(self.getId());
    ui->ageLineEdit   ->setText(QString::number(self.getAge()));
    ui->deptLineEdit  ->setText(self.getDepartment());
    ui->emailLineEdit ->setText(self.getEmail());
    ui->genderLineEdit->setText(self.getGender());
    ui->phoneLineEdit ->setText(self.getPhone());
    ui->nameLineEdit  ->setText(self.getName());
    ui->majorLineEdit ->setText(self.getTitle());
    setWindowTitle(self.getName() + "教师的信息");
}


void TeacherInfo::stuChangeTopic(Teacher teacher, Topic topic, Selection selection)
{
    (void)topic;
    (void)selection;
    self = teacher;
    loadInfo();
    hideAllBtn();
}
