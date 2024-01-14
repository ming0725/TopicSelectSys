#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class Client;
}

/// @brief 客户端抽象基类，登录成功后显示的客户端
class Client : public QWidget
{
    Q_OBJECT
public:
    /// @brief 构造函数，设置ui和关闭窗口自动释放资源，居中显示等
    explicit Client(QWidget *parent = nullptr);
    virtual ~Client();

    /// @brief 获取客户端大标题
    /// @return 学生端，教师端，管理员端等字符串
    virtual QString getClientTitle() = 0;

    /// @brief 获取客户端用户名和称呼
    /// @return 名字+同学、名字+老师等
    virtual QString getUserTitle() = 0;

protected:
    /**
     * @brief 使用模板方法设计模式
     * 初始化函数，将菜单，大标题，用户称呼等初始化到客户端
     * 子类继承实现接口后无需再设置
     * */
    void init();

    /// @brief 菜单root
    virtual void addTreeItems(QTreeWidgetItem* root) = 0;

    /// @brief 在stackedWidget中添加窗口，即按下菜单选项跳转的窗口
    virtual void addWidgets() = 0;

private slots:
    /**
     * @brief 按下退出后直接关闭程序
     * 若要返回登录界面需要点击右上角的X号
     * */
    void on_exitPushButton_clicked();

protected:
    Ui::Client *ui;
};

#endif // CLIENT_H
