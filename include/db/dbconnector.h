#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QString>
#include <QDebug>

// 打印SQL语句，方便查看执行的SQL，能判断哪里出了问题
#define OUTPUT_SQL(x) \
qDebug () << __FILE__ << ": Line" << __LINE__\
          << ": In function"\
          << __FUNCTION__ << "():\n        SQL:"\
          << x << '\n'

/// @brief 数据库连接抽象类，需要继承实现
class DBConnector
{
public:
    DBConnector() = default;
    virtual ~DBConnector() = default;

    /// @brief 连接到数据库函数
    virtual bool connect(
        QString user,
        QString password,
        QString database,
        QString ip,
        unsigned short port
    ) = 0;

    /// @brief 更新数据库
    virtual bool update(QString sql) = 0;

    /// @brief 查询数据库
    virtual bool query(QString sql) = 0;

    /// @brief 查询结果集切换到下一行，并且返回下一行是否存在
    virtual bool next() = 0;

    /// @brief 根据索引值获取查询结果集中某列的数据
    virtual QString value(int index) = 0;

    /// @brief 最后一次执行sql或连接的错误
    virtual QString lastError() = 0;

    /// @brief 获取查询结果集中的列数
    virtual int getResultField() = 0;
};

#endif // DBCONNECTOR_H
