#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include "information.h"
#include "student.h"
#include "studentmodel.h"

/// @brief 学生信息
class StudentInfo : public Information
{
public:
    StudentInfo(QWidget *parent = nullptr);
    StudentInfo(QString stuId, QWidget *parent = nullptr);
    StudentInfo(Student stu, QWidget *parent = nullptr);

private:
    void loadInfo() override;
    void commit() override;
    void modifyPwd() override;

private:
    Student self;
    StudentModel studentModel;
};

#endif // STUDENTINFO_H
