#ifndef MODIFYPASSWORD_H
#define MODIFYPASSWORD_H

#include <QDialog>
#include <functional>
#include "student.h"
#include "teacher.h"
#include "admin.h"

namespace Ui {
class ModifyPassword;
}

/// @brief 修改密码对话框
class ModifyPassword : public QDialog
{
    Q_OBJECT
    using Callback = std::function<void(QString&)>;

public:
    explicit ModifyPassword(QDialog *parent = nullptr);
    explicit ModifyPassword(Student &student, QDialog *parent = nullptr);
    explicit ModifyPassword(Teacher &teacher, QDialog *parent = nullptr);
    explicit ModifyPassword(Admin &admin, QDialog *parent = nullptr);
    ~ModifyPassword();

private:
    void modifyStudentPwd(QString& newPwd);
    void modifyTeacherPwd(QString& newPwd);
    void modifyAdminPwd(QString& newPwd);

private slots:
    void on_commitPushButton_clicked();
    void on_cancelPushButton_clicked();

private:
    Ui::ModifyPassword *ui;
    Callback callback;
    QString oldPwd;
    Student student;
    Teacher teacher;
    Admin admin;
};

#endif // MODIFYPASSWORD_H
