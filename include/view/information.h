#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>

namespace Ui {
class Information;
}
/**
 * @brief 信息基类
 * 显示学生，教师，管理员的信息
 * 客户端主页加载登陆者信息
 * 或者点开某个学生或教师详细按钮展示
 * */
class Information : public QWidget
{
    Q_OBJECT
public:
    /// @brief 构造函数，设置ui和关闭窗口自动释放资源
    explicit Information(QWidget *parent = nullptr);
    virtual ~Information();

    /// @brief 模板方法，调用基类实现的方法
    /// @return 返回指向this
    Information* init();

    /**
     * @brief 隐藏所有按钮，作为客户端自己的个人信息时不使用
     * 当学生点开教师详细信息时需要隐藏
     * 这些按钮的功能是修改个人信息
     * @return 返回this
     * */
    Information* hideAllBtn();

    /// @brief 隐藏修改密码按钮
    /// @return 返回this
    Information* hideModifyPwdBtn();

protected:

    /// @brief 开启或关闭修改模式，即输入栏开启或禁用
    /// @param mode 开启true 关闭false
    virtual void modifyMode(bool mode);

    /// @brief 按下提交后获取输入栏信息并修改数据库
    virtual void commit() = 0;

    /// @brief 按下修改密码后弹出修改窗口
    virtual void modifyPwd() = 0;

    /// @brief 查询的信息并加载到输入框中
    virtual void loadInfo() = 0;

private slots:
    /// @brief 按下修改信息按钮的槽函数
    void on_modifyPushButton_clicked();

    /// @brief 按下提交按钮的槽函数
    void on_commitPushButton_clicked();

    /// @brief 按下取消按钮的槽函数
    void on_cancelPushButton_clicked();

    /// @brief 按下修改密码按钮的槽函数
    void on_modifyPwdPushButton_clicked();

protected:
    Ui::Information *ui;
};

#endif // INFORMATION_H
