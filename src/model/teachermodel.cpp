#include "teachermodel.h"
#include "connectionpool.h"

#define TEA_ID 0
#define TEA_NAME 1
#define TEA_GENDER 2
#define TEA_AGE 3
#define TEA_EMAIL 4
#define TEA_PHONE 5
#define TEA_DEPART 6
#define TEA_TITLE 7
#define TEA_PWD 8


TeacherModel::TeacherModel()
{
}

Teacher TeacherModel::queryById(QString &id)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM teacher WHERE tea_id = '%1'").arg(id);
    conn->query(sql);
    if (conn->next())
    {
        Teacher teacher;
        teacher.setId        (conn->value(TEA_ID));
        teacher.setAge       (conn->value(TEA_AGE).toInt());
        teacher.setName      (conn->value(TEA_NAME));
        teacher.setGender    (conn->value(TEA_GENDER));
        teacher.setDepartment(conn->value(TEA_DEPART));
        teacher.setPhone     (conn->value(TEA_PHONE));
        teacher.setEmail     (conn->value(TEA_EMAIL));
        teacher.setTitle     (conn->value(TEA_TITLE));
        teacher.setPassword  (conn->value(TEA_PWD));
        return teacher;
    }
    return Teacher();
}

bool TeacherModel::insert(Teacher &teacher)
{
    return false;
}

bool TeacherModel::remove(Teacher &teacher)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("DELETE FROM teacher WHERE tea_id = '%1'").arg(teacher.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Teacher> TeacherModel::queryAll()
{
    QVector<Teacher> teacherVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM teacher");
    conn->query(sql);
    OUTPUT_SQL(sql);
    while (conn->next())
    {
        Teacher teacher;
        teacher.setId        (conn->value(TEA_ID));
        teacher.setAge       (conn->value(TEA_AGE).toInt());
        teacher.setName      (conn->value(TEA_NAME));
        teacher.setGender    (conn->value(TEA_GENDER));
        teacher.setDepartment(conn->value(TEA_DEPART));
        teacher.setPhone     (conn->value(TEA_PHONE));
        teacher.setEmail     (conn->value(TEA_EMAIL));
        teacher.setTitle     (conn->value(TEA_TITLE));
        teacher.setPassword  (conn->value(TEA_PWD));
        teacherVec.emplace_back(teacher);
    }
    return teacherVec;
}

bool TeacherModel::update(Teacher &teacher)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "UPDATE teacher "
            "SET "
                "name         = '%1', "
                "gender       = '%2', "
                "age          = '%3', "
                "email        = '%4', "
                "department   = '%5', "
                "title        = '%6', "
                "phone_number = '%7', "
                "password     = '%8' "
            "WHERE "
                "tea_id       = '%9'")
           .arg(teacher.getName(),
                teacher.getGender(),
QString::number(teacher.getAge()),
                teacher.getEmail(),
                teacher.getDepartment(),
                teacher.getTitle(),
                teacher.getPhone(),
                teacher.getPassword(),
                teacher.getId()
    );
    OUTPUT_SQL(sql);
    return conn->update(sql);
}
