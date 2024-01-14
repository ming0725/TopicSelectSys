#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief 登录窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /// @brief 登录按钮槽函数
    void on_loginBtn_clicked();

    /// @brief 退出按钮槽函数
    void on_exitBtn_clicked();

signals:
    /// @brief 登录成功信号
    void succ(Client*);
    /// @brief 登录失败信号
    void fail();

private:
    Ui::MainWindow *ui;
    /// @brief 客户端
    Client* client;
};
#endif // MAINWINDOW_H
