#ifndef TOPICTABLE_H
#define TOPICTABLE_H

#include "topicmodel.h"
#include "infotable.h"
#include "teachermodel.h"
#include "selectionmodel.h"
#include "topicmodel.h"

/// @brief 所有题目的信息表
class TopicTable : public InfoTable
{
public:
    TopicTable(QWidget *parent = nullptr);

private:
    QVector<QString> setColName() override;
    void showData() override;
    void loadData() override;

private slots:
    void onModifyBtnClicked();
    void onDeleteBtnClicked();
    void onTopicDetailBtnClicked();
    void onTeachDetailBtnClicked();

private:
    TeacherModel teacherModel;
    SelectionModel selectionModel;
    TopicModel topicModel;
    QMap<QString, Topic>   topicMap;
    QMap<QString, Teacher> teacherMap;
    QMap<QString, int>     selectCountMap;
};

#endif // TOPICTABLE_H
