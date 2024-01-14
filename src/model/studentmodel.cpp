#include "studentmodel.h"
#include "connectionpool.h"

#define STU_ID 0
#define STU_NAME 1
#define STU_GENDER 2
#define STU_AGE 3
#define STU_EMAIL 4
#define STU_PHONE 5
#define STU_DEPART 6
#define STU_MAJOR 7
#define STU_PWD 8

StudentModel::StudentModel() {}

Student StudentModel::queryById(QString &id)
{
    QString sql = QString("SELECT * FROM student WHERE stu_id = '%1'").arg(id);
    auto conn = ConnectionPool::instance()->getConnection();
    OUTPUT_SQL(sql);
    conn->query(sql);
    if (conn->next())
    {
        Student stu;
        stu.setId(conn->value(STU_ID));
        stu.setPassword(conn->value(STU_PWD));
        stu.setAge(conn->value(STU_AGE).toInt());
        stu.setDepartment(conn->value(STU_DEPART));
        stu.setGender(conn->value(STU_GENDER));
        stu.setEmail(conn->value(STU_EMAIL));
        stu.setPhone(conn->value(STU_PHONE));
        stu.setMajor(conn->value(STU_MAJOR));
        stu.setName(conn->value(STU_NAME));
        return stu;
    }
    else
        return Student();
}

bool StudentModel::insert(Student &stu)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("INSERT student VALUES('%1', '%2', '%3', %4, '%5', '%6', '%7', '%8', '%9')").
                arg(stu.getId(),
                    stu.getName(),
                    stu.getGender(),
    QString::number(stu.getAge()),
                    stu.getEmail(),
                    stu.getPhone(),
                    stu.getDepartment(),
                    stu.getMajor(),
                    stu.getPassword());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool StudentModel::remove(Student &stu)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("DELETE FROM student WHERE stu_id = '%1'").arg(stu.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Student> StudentModel::queryAll()
{
    QVector<Student> stuVec{};
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM student");
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Student stu;
        stu.setId        (conn->value(STU_ID));
        stu.setAge       (conn->value(STU_AGE).toInt());
        stu.setName      (conn->value(STU_NAME));
        stu.setEmail     (conn->value(STU_EMAIL));
        stu.setPhone     (conn->value(STU_PHONE));
        stu.setMajor     (conn->value(STU_MAJOR));
        stu.setGender    (conn->value(STU_GENDER));
        stu.setPassword  (conn->value(STU_PWD));
        stu.setDepartment(conn->value(STU_DEPART));
        stuVec.push_back(stu);
    }
    return stuVec;
}

bool StudentModel::update(Student &stu)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
                    "UPDATE student "
                    "SET "
                        "name         = '%1', "
                        "gender       = '%2', "
                        "age          = '%3', "
                        "email        = '%4', "
                        "department   = '%5', "
                        "major        = '%6', "
                        "phone_number = '%7', "
                        "password     = '%8' "
                    "WHERE "
                        "stu_id       = '%9'").
                arg(stu.getName(),
                    stu.getGender(),
    QString::number(stu.getAge()),
                    stu.getEmail(),
                    stu.getDepartment(),
                    stu.getMajor(),
                    stu.getPhone(),
                    stu.getPassword(),
                    stu.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool StudentModel::updateId(Student &stu, QString &newId)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
                    "UPDATE student "
                        "SET "
                        "stu_id = '%1' "
                    "WHERE "
                        "stu_id = '%2'").
                arg(newId, stu.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}