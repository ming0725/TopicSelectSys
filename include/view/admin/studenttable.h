#ifndef STUDENTTABLE_H
#define STUDENTTABLE_H

#include "infotable.h"
#include "studentmodel.h"
#include "teachermodel.h"
#include "topicmodel.h"
#include "selectionmodel.h"

/// @brief 所有学生的信息表
class StudentTable : public InfoTable
{
public:
    StudentTable(QWidget *parent = nullptr);

private:
    QVector<QString> setColName() override;
    void showData() override;
    void addBtn() override;
    void loadData() override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onStuInfoBtnClicked();
    void onAddStuBtnClicked();
    void onStatusBtnClicked();
    void onModifyBtnClicked();
    void onDelStuBtnClicked();
    void onResetPwdBtnClicked();

private:
    QMap<QString, Student> stuMap;
    QMap<QString, Selection> selectionMap;
    QMap<QString, Topic> topicMap;
    QMap<QString, Teacher> teacherMap;
    SelectionModel selectionModel;
    TopicModel topicModel;
    TeacherModel teacherModel;
    StudentModel studentModel;
};

#endif // STUDENTTABLE_H
