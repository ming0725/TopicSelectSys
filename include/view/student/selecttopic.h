#ifndef SELECTTOPIC_H
#define SELECTTOPIC_H

#include <QVector>
#include "infotable.h"
#include "topicmodel.h"
#include "selectionmodel.h"
#include "topicmodel.h"
#include "teachermodel.h"

/// @brief 学生选题的信息表
class SelectTopic : public InfoTable
{
    Q_OBJECT
public:
    SelectTopic(QWidget *parent = nullptr);

private:
    void showData() override;
    void loadData() override;
    QVector<QString> setColName() override;

private slots:
    void onTeaInfoButtonClicked();
    void onTopicInfoButtonClicked();
    void onSelectButtonClicked();

signals:
    /// @brief 修改选题后发出的信号
    /// @param teacher 修改后的选题所属教师
    /// @param topic 修改后的选题
    /// @param selection 修改后的选择信息
    void dataUpdate(Teacher teacher, Topic topic, Selection selection);

private:
    QMap<QString, Teacher> teacherMap;
    QMap<QString, Topic> topicMap;
    QMap<QString, int> selectCountMap;
    TopicModel topicModel;
    TeacherModel teacherModel;
    SelectionModel selectionModel;
    Selection mySelection;
};

#endif // SELECTTOPIC_H
