#include "account.h"

Account Account::instance_ = Account();
Account::Account() {}

Account &Account::instance()
{
    return instance_;
}

void Account::setInfo(Student &student)
{
    id = student.getId();
}

void Account::setInfo(Teacher &teacher)
{
    id = teacher.getId();
}

void Account::setInfo(Admin &admin)
{
    id = admin.getId();
}

Account *Account::pInstance()
{
    return &instance_;
}

QString &Account::getId()
{
    return id;
}

void Account::setId(const QString &id)
{
    Account::id = id;
}


const QString &Account::getName() const
{
    return name;
}

void Account::setName(const QString &name)
{
    Account::name = name;
}
