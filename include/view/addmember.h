#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>
#include <functional>
#include "studentmodel.h"
#include "teachermodel.h"

namespace Ui {
class AddMember;
}

/// @brief 添加学生或教师的对话框
class AddMember : public QDialog
{
    Q_OBJECT
    /// @brief 返回类型为void且无参数的回调函数
    using Callback = std::function<void()>;
public:
    /// @brief 该对话框模式
    enum Mode {
        AddStudent, // 添加学生模式
        AddTeacher  // 添加教师模式
    };

public:
    /// @brief 构造函数，根据模式绑定回调
    /// @param mode 添加教师或学生
    /// @param parent QObject对象树的父对象指针
    explicit AddMember(Mode mode,  QWidget *parent = nullptr);

    ~AddMember();

private slots:
    /// @brief 按下提交按钮的槽函数
    void on_commitPushButton_clicked();
    /// @brief 按下取消按钮的槽函数
    void on_cancelPushButton_clicked();

private:
    /// @brief 窗口的ui文件
    Ui::AddMember *ui;
    /// @brief 学生model，用来对学生的增删改查
    StudentModel studentModel;
    /// @brief 教师model，用来对教师的增删改查
    TeacherModel teacherModel;
    /// @brief 回调函数，根据绑定的函数来进行哪一种模式
    Callback callback;
};

#endif // ADDMEMBER_H
