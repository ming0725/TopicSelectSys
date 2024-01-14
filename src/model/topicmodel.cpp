#include "topicmodel.h"
#include "connectionpool.h"

#define TOPIC_ID 0
#define TOPIC_TEA_ID 1
#define TOPIC_TITLE 2
#define TOPIC_DESC 3
#define TOPIC_REQUIRE 4
#define TOPIC_MAX_NUM 5

TopicModel::TopicModel()
{

}

Topic TopicModel::queryById(QString &id)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM topic WHERE topic_id = '%1'").arg(id);
    OUTPUT_SQL(sql);
    conn->query(sql);
    if (conn->next())
    {
        Topic topic;
        topic.setId         (conn->value(TOPIC_ID));
        topic.setDesc       (conn->value(TOPIC_DESC));
        topic.setMax        (conn->value(TOPIC_MAX_NUM).toInt());
        topic.setTitle      (conn->value(TOPIC_TITLE));
        topic.setTeacherId  (conn->value(TOPIC_TEA_ID));
        topic.setRequirement(conn->value(TOPIC_REQUIRE));
        return topic;
    }
    return Topic();
}

bool TopicModel::insert(Topic &topic)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("INSERT INTO topic VALUES('%1', '%2', '%3', '%4', '%5', %6)")
            .arg(topic.getId(),
                 topic.getTeacherId(),
                 topic.getTitle(),
                 topic.getDesc(),
                 topic.getRequirement(),
                 QString::number(topic.getMax()));
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool TopicModel::remove(Topic &topic)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("DELETE FROM topic WHERE topic_id = '%1'")
            .arg(topic.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Topic> TopicModel::queryAll()
{
    QVector<Topic> topicVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM topic");
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Topic topic;
        topic.setId         (conn->value(TOPIC_ID));
        topic.setDesc       (conn->value(TOPIC_DESC));
        topic.setMax        (conn->value(TOPIC_MAX_NUM).toInt());
        topic.setTitle      (conn->value(TOPIC_TITLE));
        topic.setTeacherId  (conn->value(TOPIC_TEA_ID));
        topic.setRequirement(conn->value(TOPIC_REQUIRE));
        topicVec.emplace_back(topic);
    }
    return topicVec;
}

bool TopicModel::update(Topic &topic)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "UPDATE topic "
            "SET "
                "tea_id      = '%1', "
                "topic_title = '%2', "
                "description = '%3', "
                "requirement = '%4', "
                "max_num     =  %5 "
            "WHERE "
                "topic_id    = '%6'")
            .arg(topic.getTeacherId(),
                 topic.getTitle(),
                 topic.getDesc(),
                 topic.getRequirement(),
 QString::number(topic.getMax()),
                 topic.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Topic> TopicModel::queryByTeacherId(QString &teacherId)
{
    QVector<Topic> topicVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM topic WHERE tea_id = '%1'").arg(teacherId);
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Topic topic;
        topic.setId         (conn->value(TOPIC_ID));
        topic.setDesc       (conn->value(TOPIC_DESC));
        topic.setMax        (conn->value(TOPIC_MAX_NUM).toInt());
        topic.setTitle      (conn->value(TOPIC_TITLE));
        topic.setTeacherId  (conn->value(TOPIC_TEA_ID));
        topic.setRequirement(conn->value(TOPIC_REQUIRE));
        topicVec.emplace_back(topic);
    }
    return topicVec;
}
