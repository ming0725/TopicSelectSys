#ifndef TEACHER_H
#define TEACHER_H

#include <QString>

class Teacher
{
public:
    Teacher() = default;

    const QString &getId() const
    {
        return id;
    }

    void setId(const QString &id)
    {
        Teacher::id = id;
    }

    const QString &getName() const
    {
        return name;
    }

    void setName(const QString &name)
    {
        Teacher::name = name;
    }

    const QString &getPhone() const
    {
        return phone;
    }

    void setPhone(const QString &phone)
    {
        Teacher::phone = phone;
    }

    const QString &getGender() const
    {
        return gender;
    }

    void setGender(const QString &gender)
    {
        Teacher::gender = gender;
    }

    const QString &getEmail() const
    {
        return email;
    }

    void setEmail(const QString &email)
    {
        Teacher::email = email;
    }

    const QString &getDepartment() const
    {
        return department;
    }

    void setDepartment(const QString &department)
    {
        Teacher::department = department;
    }

    const QString &getTitle() const
    {
        return title;
    }

    void setTitle(const QString &title)
    {
        Teacher::title = title;
    }

    const QString &getPassword() const
    {
        return password;
    }

    void setPassword(const QString &password)
    {
        Teacher::password = password;
    }

    int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        Teacher::age = age;
    }

private:
    QString id;
    QString name;
    QString phone;
    QString gender;
    QString email;
    QString department;
    QString title;
    QString password;
    int age;
};

#endif // TEACHER_H
