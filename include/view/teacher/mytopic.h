#ifndef MYTOPIC_H
#define MYTOPIC_H

#include "infotable.h"
#include "topicmodel.h"
#include "selectionmodel.h"
#include "teachermodel.h"

/// @brief 该教师的所有选题的信息表
class MyTopic : public InfoTable
{
public:
    MyTopic(QWidget *parent = nullptr);

private slots:
    void onAddTopicBtnClicked();
    void onDetailBtnClicked();
    void onModifyBtnClicked();
    void onDeleteBtnClicked();

private:
    QVector<QString> setColName() override;
    void showData() override;
    void loadData() override;
    void addBtn() override;

private:
    TopicModel topicModel;
    SelectionModel selectionModel;
    TeacherModel teacherModel;
    QMap<QString, Topic> topicMap;
    QMap<QString, int> selectCountMap;
};



#endif // MYTOPIC_H
