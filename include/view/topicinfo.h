#ifndef TOPICINFO_H
#define TOPICINFO_H

#include <QWidget>
#include "teacher.h"
#include "topic.h"
#include "selection.h"

namespace Ui {
class TopicInfo;
}

/// @brief 选题具体信息窗口
class TopicInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TopicInfo(QWidget *parent = nullptr);

    /// @brief 根据学生学号显示学生选的题目信息，包括该学生的选题状态，学生用
    /// @param stuId 需要查询的学生学号
    explicit TopicInfo(QString stuId, QWidget *parent = nullptr);

    /// @brief 根据教师和题目显示题目信息，教师和管理员使用，不显示选题状态
    /// @param teacher 该题目所属的教师
    /// @param topic 选题
    explicit TopicInfo(Teacher &teacher, Topic &topic, QWidget *parent = nullptr);

    /// @brief 根据教师，选题和选择显示题目信息，学生用
    /// @param teacher 出题教师
    /// @param topic 选题
    /// @param selection 该学生的选题状态
    explicit TopicInfo(Teacher &teacher, Topic &topic, Selection &selection, QWidget *parent = nullptr);

    ~TopicInfo();

private:
    /// @brief 在ui上设置好教师的题目信息
    /// @param teacher 教师
    /// @param topic 教师出的选题
    void setTeacherTopicInfo(Teacher &teacher, Topic &topic);

public slots:
    /// @brief 槽函数，当学生审核未通过可以修改选题，修改后需重新加载
    /// @param teacher 修改后选题所属的新教师
    /// @param topic 修改后的新选题
    /// @param selection 修改后的的选择信息
    /// @see include/view/student/selecttopic.h#dataUpdate()
    void stuChangeTopic(Teacher teacher, Topic topic, Selection selection);

private:
    Ui::TopicInfo *ui;
};

#endif // TOPICINFO_H
