#ifndef TEACHERTABLE_H
#define TEACHERTABLE_H

#include "infotable.h"
#include "teachermodel.h"

/// @brief 所有教师的信息表
class TeacherTable : public InfoTable
{
public:
    TeacherTable(QWidget *parent = nullptr);

private:
    QVector<QString> setColName() override;
    void showData() override;
    void loadData() override;
    void addBtn() override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onDetailBtnClicked();
    void onModifyBtnClicked();
    void onAddTeaBtnClicked();
    void onDelTeaBtnClicked();
    void onResetPwdBtnClicked();

private:
    TeacherModel teacherModel;
    QMap<QString, Teacher> teacherMap;
};

#endif // TEACHERTABLE_H
