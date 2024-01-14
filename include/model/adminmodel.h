#ifndef ADMINMODEL_H
#define ADMINMODEL_H

#include <QString>
#include <QVector>
#include "admin.h"

class AdminModel
{
public:
    AdminModel();

    /// @brief 根据管理员id查找，并返回一个管理员
    Admin queryById(QString &id);

    /// @brief 查询所有管理员，返回一个管理员数组
    QVector<Admin> queryAll();

    /// @brief 插入
    /// @throws 抛出插入失败的信息
    bool insert(Admin &admin);

    /// @brief 删除
    bool remove(Admin &admin);

    /// @brief 更新
    /// @throws 抛出更新失败的信息
    bool update(Admin &admin);

    /// @brief 更新id
    /// @param admin 需要更新id的管理员
    /// @param newId 新的id
    /// @throws 抛出更新id失败的信息
    bool updateId(Admin &admin, QString &newId);
};

#endif // ADMINMODEL_H
