#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QString>
#include <QVector>
#include "student.h"

class StudentModel
{
public:
    StudentModel();

    /// @brief 根据id查询学生
    Student queryById(QString &id);

    /// @brief 插入
    /// @throws 抛出插入失败的信息
    bool insert(Student &stu);

    /// @brief 删除
    bool remove(Student &stu);

    /// @brief 修改
    /// @throws 抛出修改失败的信息
    bool update(Student &stu);

    /// @brief 修改id
    /// @throws 抛出修改id失败的信息
    bool updateId(Student &stu, QString &newId);

    /// @brief 查询所有学生
    QVector<Student> queryAll();
};

#endif // STUDENTMODEL_H
