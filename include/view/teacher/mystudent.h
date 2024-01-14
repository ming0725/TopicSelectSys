#ifndef MYSTUDENT_H
#define MYSTUDENT_H

#include "infotable.h"
#include "studentmodel.h"
#include "topicmodel.h"
#include "selectionmodel.h"
#include "teachermodel.h"
#include <QMap>

/// @brief 选了自己的题目已经通过的学生
class MyStudent : public InfoTable
{
public:
    MyStudent(QWidget *parent = nullptr);

private:
    QVector<QString> setColName() override;
    void showData() override;
    void loadData() override;

private slots:
    void onStuInfoBtnClicked();
    void onTopicInfoBtnClicked();

private:
    StudentModel studentModel;
    SelectionModel selectionModel;
    TopicModel topicModel;
    TeacherModel teacherModel;
    QMap<QString, QPair<Student, Topic>> stuTopicMap;
    QVector<Selection> selectVec;
};

#endif // MYSTUDENT_H
