#ifndef TEACHERCLIENT_H
#define TEACHERCLIENT_H

#include "client.h"

/// @brief 教师端
class TeacherClient : public Client
{
public:
    TeacherClient();
    QString getClientTitle() override;
    QString getUserTitle() override;
    void addTreeItems(QTreeWidgetItem *root) override;
    void addWidgets() override;
};

#endif // TEACHERCLIENT_H
