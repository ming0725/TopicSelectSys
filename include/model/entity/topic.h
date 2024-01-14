#ifndef TOPIC_H
#define TOPIC_H

#include <QString>

class Topic
{
public:
    Topic() = default;

    const QString &getId() const
    {
        return id;
    }

    void setId(const QString &id)
    {
        Topic::id = id;
    }

    const QString &getTitle() const
    {
        return title;
    }

    void setTitle(const QString &title)
    {
        Topic::title = title;
    }

    const QString &getDesc() const
    {
        return desc;
    }

    void setDesc(const QString &desc)
    {
        Topic::desc = desc;
    }

    const QString &getRequirement() const
    {
        return requirement;
    }

    void setRequirement(const QString &requirement)
    {
        Topic::requirement = requirement;
    }

    QString &getTeacherId()
    {
        return teacherId;
    }

    void setTeacherId(const QString &teacherId)
    {
        Topic::teacherId = teacherId;
    }

    int getMax() const
    {
        return max;
    }

    void setMax(int max)
    {
        Topic::max = max;
    }

private:
    QString id;
    QString title;
    QString desc;
    QString requirement;
    QString teacherId;
    int max;
};

#endif // TOPIC_H
