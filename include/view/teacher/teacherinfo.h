#ifndef TEACHERINFO_H
#define TEACHERINFO_H

#include "information.h"
#include "teachermodel.h"
#include "studentmodel.h"
#include "topic.h"
#include "selection.h"

/// @brief 教师信息
class TeacherInfo : public Information
{
public:
    explicit TeacherInfo(QWidget *parent = nullptr);
    explicit TeacherInfo(Teacher teacher, QWidget *parent = nullptr);
    explicit TeacherInfo(QString stuId, QWidget *parent = nullptr);

public slots:
    void stuChangeTopic(Teacher teacher, Topic topic, Selection selection);

protected:
    void commit() override;
    void modifyPwd() override;
    void loadInfo() override;

private:
    Teacher self;
    TeacherModel teacherModel;
};

#endif // TEACHERINFO_H
