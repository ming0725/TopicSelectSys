#include "selectionmodel.h"
#include "connectionpool.h"

#define SEL_STU_ID 0
#define SEL_TEA_ID 1
#define SEL_STATUS 2

SelectionModel::SelectionModel() {}


Selection SelectionModel::queryById(QString &stuId)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "SELECT * "
            "FROM selection "
            "WHERE stu_id = '%1'").arg(stuId);
    conn->query(sql);
    OUTPUT_SQL(sql);
    if (conn->next())
    {
        Selection selection;
        selection.setStudentId(stuId);
        selection.setStatus (conn->value(SEL_STATUS));
        selection.setTopicId(conn->value(SEL_TEA_ID));
        return selection;
    }
    return Selection();
}

bool SelectionModel::insert(Selection &selection)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "INSERT INTO selection "
            "VALUES('%1', '%2', '%3')")
        .arg(selection.getStudentId(), selection.getTopicId(), selection.getStatus());
    OUTPUT_SQL(sql);
    return conn->update(sql);

}

bool SelectionModel::remove(Selection &selection)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "DELETE FROM selection "
            "WHERE stu_id = '%1'")
            .arg(selection.getStudentId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Selection> SelectionModel::queryAll()
{
    QVector<Selection> selectionVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM selection");
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Selection selection;
        selection.setStatus   (conn->value(SEL_STATUS));
        selection.setTopicId  (conn->value(SEL_TEA_ID));
        selection.setStudentId(conn->value(SEL_STU_ID));
        selectionVec.emplace_back(selection);
    }
    return selectionVec;
}

bool SelectionModel::insert(Student &stu, Topic &topic)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
        "INSERT INTO selection "
        "VALUES('%1', '%2', '%3')")
    .arg(stu.getId(), topic.getId(), "审核中");
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool SelectionModel::update(Selection &selection)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
        "UPDATE selection "
        "SET "
            "topic_id = '%1', "
            "status   = '%2' "
        "WHERE "
            "stu_id   = '%3'")
        .arg(selection.getTopicId(),
             selection.getStatus(),
             selection.getStudentId()
    );
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QMap<QString, int> SelectionModel::selectCount()
{
    QMap<QString, int> map;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "SELECT topic_id, COUNT(*) "
            "FROM selection "
            "WHERE status = '通过' "
            "GROUP BY topic_id");
    conn->query(sql);
    OUTPUT_SQL(sql);
    while (conn->next())
    {
        map.insert(conn->value(0), conn->value(1).toInt());
    }
    return map;
}

QString SelectionModel::querySelectedTeacherIdByStuId(QString &stu_id)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
        "SELECT s.stu_id, t.tea_id "
        "FROM selection s "
        "INNER JOIN topic t ON s.topic_id = t.topic_id "
        "WHERE s.stu_id = '%1'").arg(stu_id);
    conn->query(sql);
    OUTPUT_SQL(sql);
    if (conn->next())
        return conn->value(1);
    return QString();
}

QVector<Selection> SelectionModel::queryByTeaIdAndStatus(QString &teacherId, QString &status)
{
    QVector<Selection> selectionVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT s.stu_id, s.topic_id, s.status "
                  "FROM selection s "
                  "INNER JOIN "
                    "topic t ON s.topic_id = t.topic_id "
                  "WHERE "
                    "t.tea_id = '%1' AND s.status = '%2'").arg(teacherId, status);
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Selection selection;
        selection.setStatus   (conn->value(SEL_STATUS));
        selection.setTopicId  (conn->value(SEL_TEA_ID));
        selection.setStudentId(conn->value(SEL_STU_ID));
        selectionVec.emplace_back(selection);
    }
    return selectionVec;
}
