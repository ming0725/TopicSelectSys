#ifndef ADMINCLIENT_H
#define ADMINCLIENT_H

#include "client.h"

/// @brief 管理员端
class AdminClient : public Client
{
public:
    AdminClient(QWidget *parent = nullptr);
    QString getClientTitle() override;
    QString getUserTitle() override;
    void addTreeItems(QTreeWidgetItem *root) override;
    void addWidgets() override;
};

#endif // ADMINCLIENT_H
