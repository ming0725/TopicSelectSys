#ifndef APPROVEAPPLICATION_H
#define APPROVEAPPLICATION_H

#include "infotable.h"
#include "selectionmodel.h"
#include "studentmodel.h"
#include "topicmodel.h"
#include "teachermodel.h"

/// @brief 选了自己的题目在审核中的学生信息表，可以审核是否通过
class ApproveApplication : public InfoTable
{
    Q_OBJECT
public:
    ApproveApplication(QWidget *parent = nullptr);
    ApproveApplication(QString id, QWidget *parent = nullptr);

private slots:
    void onTopicInfoBtnClicked();
    void onValidBtnClicked();

private:
    QVector<QString> setColName() override;
    void showData() override;
    void loadData() override;

private:
    Teacher self;
    TopicModel topicModel;
    StudentModel studentModel;
    SelectionModel selectionModel;
    QMap<QString, QPair<Student, Topic>> stuTopicMap;
    QVector<Selection> selectVec;
};

#endif // APPROVEAPPLICATION_H
