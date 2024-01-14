#ifndef MODIFYTOPIC_H
#define MODIFYTOPIC_H

#include <QDialog>
#include <functional>
#include "topicmodel.h"
#include "teachermodel.h"

namespace Ui {
class ModifyTopic;
}

/// @brief 修改选题和添加选题
class ModifyTopic : public QDialog
{
    Q_OBJECT

public:
    /// @brief 连接一些槽函数
    explicit ModifyTopic(QWidget *parent = nullptr);

    /// @brief 修改选题
    /// @param topic 需要修改的选题
    explicit ModifyTopic(Topic topic, QWidget *parent = nullptr);

    /// @brief 教师添加选题
    /// @param teacher 需要添加选题的教师
    explicit ModifyTopic(Teacher teacher, QWidget *parent = nullptr);

    ~ModifyTopic();

private slots:
    /// @brief 按下提交按钮槽函数
    void onCommitBtnClicked();

private:
    Ui::ModifyTopic *ui;
    TopicModel topicModel;
    Topic topic;
    TeacherModel teacherModel;
    Teacher teacher;
    std::function<void()> callback;
};

#endif // MODIFYTOPIC_H
