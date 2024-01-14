#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include "dbconnector.h"
#include <mysql.h>
#include <QException>

class MysqlConnector : public DBConnector
{
public:
    MysqlConnector();
    ~MysqlConnector() override;

    /// @brief 连接到数据库函数
    bool connect(
        QString user,
        QString password,
        QString database,
        QString ip,
        unsigned short port = 3306
    ) override;

    /// @brief 更新数据库
    /// @param sql 要执行的SQL
    /// @throws 抛出执行SQL产生的错误信息
    bool update(QString sql) override;

    /// @brief 查询数据库
    /// @param sql 要执行的SQL
    /// @throws 抛出执行SQL产生的错误信息
    bool query(QString sql) override;

    /// @brief 查询结果集切换到下一行，并且返回下一行是否存在
    bool next() override;

    /// @brief 获取查询结果集中的列数
    int getResultField() override;

    /// @brief 查询结果集切换到下一行，并且返回下一行是否存在
    QString value(int index) override;

    /// @brief 最后一次执行SQL或连接的错误
    /// @return 错误信息
    QString lastError() override;

private:
    /// @brief 释放结果集
    void free_result();

private:
    /// @brief 连接和查询要用到的东西
    MYSQL* m_conn = nullptr;
    MYSQL_RES* m_result = nullptr;
    MYSQL_ROW m_row = nullptr;
};


// 查询数据库的错误使用抛出异常的方式
class MysqlException : public QException
{
public:
    MysqlException(const QString &errorMessage);
    // 重写what函数
    const char* what() const noexcept override;
private:
    // 异常信息
    QString m_errorMessage;
};

#endif // MYSQLCONNECTOR_H
