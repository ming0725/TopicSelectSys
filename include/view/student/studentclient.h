#ifndef STUDENTCLIENT_H
#define STUDENTCLIENT_H

#include "client.h"

/// @brief 学生端
class StudentClient : public Client
{
public:
    StudentClient(QWidget *parent = nullptr);
    QString getClientTitle() override;
    QString getUserTitle() override;
    void addTreeItems(QTreeWidgetItem* root) override;
    void addWidgets() override;
};

#endif // STUDENTCLIENT_H
