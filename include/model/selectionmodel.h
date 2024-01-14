#ifndef SELECTIONMODEL_H
#define SELECTIONMODEL_H

#include "selection.h"
#include "student.h"
#include "topic.h"

#include <QString>
#include <QVector>
#include <QMap>

class SelectionModel
{
public:
    SelectionModel();

    /// @brief 根据学号查询一个选择
    /// @return 选择
    Selection queryById(QString &stuId);

    /// @brief 插入选择根据一个选择对象
    /// @throws 抛出插入失败的信息
    bool insert(Selection &selection);

    /// @brief 根据学生和选题插入
    /// @throws 抛出插入失败的信息
    bool insert(Student &stu, Topic &topic);

    /// @brief 删除
    /// @throws 抛出删除失败的信息
    bool remove(Selection &selection);

    /// @brief 更新
    /// @throws 抛出更新失败的信息
    bool update(Selection &selection);

    /// @brief 查询每一个选题对应的选题人数（已经通过了才算，审核中和不通过不计入）
    /// @return 题目号-选题人数Map
    QMap<QString, int> selectCount();

    /// @brief 查询全部选择
    QVector<Selection> queryAll();

    /// @brief 根据教师id，状态查询选择 一般用来教师端查询选择了自己并且为审核中的学生
    /// @param teacherId 选择了该教师的选题的教师id号
    /// @param status 选题的状态
    /// @return 返回选择了该教师，并且状态为status的选择
    QVector<Selection> queryByTeaIdAndStatus(QString &teacherId, QString &status);

    /// @brief 根据学号查询自己选择了的教师的id
    /// @param stu_id 学号
    /// @return 教师的id
    QString querySelectedTeacherIdByStuId(QString &stu_id);
};

#endif // SELECTIONMODEL_H
