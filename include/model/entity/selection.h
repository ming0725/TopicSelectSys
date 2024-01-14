#ifndef SELECTION_H
#define SELECTION_H

#include <QString>

class Selection
{
public:
    Selection() = default;

    QString &getStudentId()
    {
        return studentId;
    }

    void setStudentId(const QString &studentId)
    {
        Selection::studentId = studentId;
    }

    QString &getTopicId()
    {
        return topicId;
    }

    void setTopicId(const QString &topicId)
    {
        Selection::topicId = topicId;
    }

    const QString &getStatus() const
    {
        return status;
    }

    void setStatus(const QString &status)
    {
        Selection::status = status;
    }

private:
    QString studentId;
    QString topicId;
    QString status;
};

#endif // SELECTION_H
