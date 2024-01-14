#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student() = default;

    const QString &getId() const
    {
        return id;
    }

    void setId(const QString &id)
    {
        Student::id = id;
    }

    const QString &getName() const
    {
        return name;
    }

    void setName(const QString &name)
    {
        Student::name = name;
    }

    const QString &getPhone() const
    {
        return phone;
    }

    void setPhone(const QString &phone)
    {
        Student::phone = phone;
    }

    const QString &getGender() const
    {
        return gender;
    }

    void setGender(const QString &gender)
    {
        Student::gender = gender;
    }

    const QString &getEmail() const
    {
        return email;
    }

    void setEmail(const QString &email)
    {
        Student::email = email;
    }

    const QString &getDepartment() const
    {
        return department;
    }

    void setDepartment(const QString &department)
    {
        Student::department = department;
    }

    const QString &getMajor() const
    {
        return major;
    }

    void setMajor(const QString &major)
    {
        Student::major = major;
    }

    const QString &getPassword() const
    {
        return password;
    }

    void setPassword(const QString &password)
    {
        Student::password = password;
    }

    int getAge() const
    {
        return age;
    }

    void setAge(int age)
    {
        Student::age = age;
    }

private:
    QString id;
    QString name;
    QString phone;
    QString gender;
    QString email;
    QString department;
    QString major;
    QString password;
    int age;
};

#endif // STUDENT_H
