#ifndef TEACHERMODEL_H
#define TEACHERMODEL_H

#include <QString>
#include <QVector>
#include "teacher.h"

class TeacherModel
{
public:
    TeacherModel();

    /// @brief 根据id查询教师
    Teacher queryById(QString &id);

    /// @brief 增加
    bool insert(Teacher &teacher);

    /// @brief 删除
    bool remove(Teacher &teacher);

    /// @brief 修改
    bool update(Teacher &teacher);

    /// @brief 查询所有教师
    QVector<Teacher> queryAll();
};

#endif // TEACHERMODEL_H
