#include "connectionpool.h"
#include "mysqlconnector.h"

using namespace std;

ConnectionPool::ConnectionPool()
{
    conn = new MysqlConnector;
    conn->connect(USER, PASSWORD, DATABASE, IP, PORT);
}

ConnectionPool* ConnectionPool::instance()
{
    static ConnectionPool pool;
    return &pool;
}

DBConnector* ConnectionPool::getConnection()
{
    return conn;
}


ConnectionPool::~ConnectionPool()
{
    delete conn;
}
