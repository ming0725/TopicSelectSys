#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include "student.h"
#include "admin.h"
#include "teacher.h"

/**
 * @brief 系统只能登录一个用户
 * 为了随时能拿到登录用户的信息
 * 创建一个账号类的单例
 * */
class Account
{
public:
    /// @brief 弃置拷贝移动构造和等号赋值
    Account(const Account&) = delete;
    Account(const Account&&) = delete;
    Account& operator=(const Account&&) = delete;

    /// @brief 获取引用实例
    static Account& instance();

    /// @brief 获取之指针实例
    static Account* pInstance();

    /// @brief 根据不同身份设置
    void setInfo(Student&);
    void setInfo(Teacher&);
    void setInfo(Admin&);

    /// @brief get and set
    QString &getId();
    void setId(const QString &id);
    const QString &getName() const;
    void setName(const QString &name);

private:
    Account();
    static Account instance_;

private:
    QString id;
    QString name;
};



#endif // ACCOUNT_H
