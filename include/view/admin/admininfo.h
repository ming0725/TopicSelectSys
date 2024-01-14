#ifndef ADMININFO_H
#define ADMININFO_H

#include "information.h"
#include "adminmodel.h"
#include <QLabel>
#include <QLineEdit>

/// @brief 管理员信息
class AdminInfo : public Information
{
public:
    AdminInfo(QWidget *parent = nullptr);

protected:
    void commit() override;
    void modifyPwd() override;
    void loadInfo() override;

private:
    Admin self;
    AdminModel adminModel;
};

#endif // ADMININFO_H
