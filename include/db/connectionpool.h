#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include "dbconnector.h"

// 在CMakeLists.txt中设置MySQL连接的值
// mysql用户名
#ifndef USER
#endif
// mysql用户密码
#ifndef PASSWORD
#endif
// mysql ip
#ifndef IP
#endif
// mysql端口
#ifndef PORT
#endif
// mysql要连接到的数据库
#ifndef DATABASE
#endif

// 连接池类，由于没有使用多线程，所以只做了一个连接类的单例
class ConnectionPool
{
public:
    /// @brief 获取连接池实例
    /// @return 连接池单例
    static ConnectionPool* instance();

    /// @brief 在连接池中获取连接
    /// @return 返回连接类对象的指针
    DBConnector* getConnection();
    ~ConnectionPool();

public:
    /// @brief 移动，拷贝，等号赋值函数弃置
    ConnectionPool(const ConnectionPool&) = delete;
    ConnectionPool(const ConnectionPool&&) = delete;
    ConnectionPool& operator=(const ConnectionPool&) = delete;

private:
    ConnectionPool();

private:
    /// @brief 连接类指针
    DBConnector* conn;
};

#endif // CONNECTIONPOOL_H
