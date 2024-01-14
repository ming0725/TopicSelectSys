#include "MysqlConnector.h"

using namespace std;

MysqlConnector::MysqlConnector()
{
    m_conn = mysql_init(nullptr);
    mysql_set_character_set(m_conn, "utf8");
}

MysqlConnector::~MysqlConnector()
{
    if (m_conn != nullptr)
        mysql_close(m_conn);
    free_result();
}

bool MysqlConnector::connect(
    QString user,
    QString password,
    QString database,
    QString ip,
    unsigned short port)
{
    MYSQL *ptr = mysql_real_connect(
        m_conn,
        ip.toUtf8(),
        user.toUtf8(),
        password.toUtf8(),
        database.toUtf8(),
        port,
        nullptr,
        0
    );
    if (ptr != nullptr)
        return true;
    throw MysqlException(lastError());
}


bool MysqlConnector::update(QString sql)
{
    if (mysql_query(m_conn, sql.toUtf8()))
        throw MysqlException(lastError());
    return true;
}


bool MysqlConnector::query(QString sql)
{
    free_result();
    if (mysql_query(m_conn, sql.toUtf8()))
        throw MysqlException(lastError().toUtf8());
    m_result = mysql_store_result(m_conn);
    return true;
}


bool MysqlConnector::next()
{
    m_row = mysql_fetch_row(m_result);
    if (m_row != nullptr)
        return true;
    return false;
}


QString MysqlConnector::value(int index)
{
    int fields = mysql_num_fields(m_result);
    if (index >= fields || index < 0)
        return QString();
    char *val = m_row[index];
    unsigned long length = mysql_fetch_lengths(m_result)[index];
    return QString::fromUtf8(val, length);
}


void MysqlConnector::free_result()
{
    if (m_result)
    {
        mysql_free_result(m_result);
        m_result = nullptr;
    }
}


int MysqlConnector::getResultField()
{
    if (m_result == nullptr)
        return 0;
    return mysql_num_fields(m_result);
}


QString MysqlConnector::lastError()
{
    const char *error = mysql_error(m_conn);
    if (error)
        return QString(error);
    return QString();
}


MysqlException::MysqlException(const QString &errorMessage)
    : m_errorMessage(errorMessage) {}

const char *MysqlException::what() const noexcept
{
    return m_errorMessage.toUtf8();
}
