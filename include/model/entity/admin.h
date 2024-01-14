#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
public:
    Admin() = default;

    QString &getId()
    {
        return id;
    }

    void setId(const QString &id)
    {
        Admin::id = id;
    }

    const QString &getName() const
    {
        return name;
    }

    void setName(const QString &name)
    {
        Admin::name = name;
    }

    const QString &getPhone() const
    {
        return phone;
    }

    void setPhone(const QString &phone)
    {
        Admin::phone = phone;
    }

    const QString &getPassword() const
    {
        return password;
    }

    void setPassword(const QString &password)
    {
        Admin::password = password;
    }

private:
    QString id;
    QString name;
    QString phone;
    QString password;
};

#endif // ADMIN_H
