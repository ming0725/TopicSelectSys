#include "adminmodel.h"
#include "connectionpool.h"

#define ADM_ID 0
#define ADM_NAME 1
#define ADM_PHONE 2
#define ADM_PWD 3

AdminModel::AdminModel()
{

}

Admin AdminModel::queryById(QString &id)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM admin WHERE ad_id = '%1'").arg(id);
    OUTPUT_SQL(sql);
    conn->query(sql);
    if (conn->next())
    {
        Admin admin;
        admin.setId(id);
        admin.setName    (conn->value(ADM_NAME));
        admin.setPhone   (conn->value(ADM_PHONE));
        admin.setPassword(conn->value(ADM_PWD));
        return admin;
    }
    return Admin();
}

bool AdminModel::insert(Admin &admin)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("INSERT admin VALUES('%1', '%2', '%3', '%4')")
        .arg(admin.getId(), admin.getName(), admin.getPhone(), admin.getPassword());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool AdminModel::remove(Admin &admin)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("DELETE FROM admin WHERE ad_id = '%1'").arg(admin.getId());
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

QVector<Admin> AdminModel::queryAll()
{
    QVector<Admin> adminVec;
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString("SELECT * FROM admin");
    OUTPUT_SQL(sql);
    conn->query(sql);
    while (conn->next())
    {
        Admin admin;
        admin.setId      (conn->value(ADM_ID));
        admin.setName    (conn->value(ADM_NAME));
        admin.setPhone   (conn->value(ADM_PHONE));
        admin.setPassword(conn->value(ADM_PWD));
        adminVec.emplace_back(admin);
    }
    return adminVec;
}

bool AdminModel::update(Admin &admin)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "UPDATE admin "
            "SET "
                "ad_id        = '%1', "
                "name         = '%2', "
                "phone_number = '%3', "
                "password     = '%4' "
            "WHERE "
                "ad_id        = '%1'")
    .arg(admin.getId(),
         admin.getName(),
         admin.getPhone(),
         admin.getPassword()
    );
    OUTPUT_SQL(sql);
    return conn->update(sql);
}

bool AdminModel::updateId(Admin &admin, QString &newId)
{
    auto conn = ConnectionPool::instance()->getConnection();
    QString sql = QString(
            "UPDATE admin "
                "SET "
            "ad_id = '%1' "
                "WHERE "
            "ad_id = '%2'")
            .arg(newId,
                 admin.getId()
            );
    OUTPUT_SQL(sql);
    return conn->update(sql);
}
