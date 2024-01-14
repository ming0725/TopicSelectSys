#ifndef TOPICMODEL_H
#define TOPICMODEL_H

#include <QString>
#include <QVector>
#include "topic.h"

class TopicModel
{
public:
    TopicModel();

    /// @brief 根据id查询选题
    Topic queryById(QString &id);

    /// @brief 增加
    bool insert(Topic &topic);

    /// @brief 删除
    bool remove(Topic &topic);

    /// @brief 修改
    bool update(Topic &topic);

    /// @brief 查询所有选题
    QVector<Topic> queryAll();

    /// @brief 查询某教师的所有选题
    QVector<Topic> queryByTeacherId(QString &teacherId);
};

#endif // TOPICMODEL_H
