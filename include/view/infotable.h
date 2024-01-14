#ifndef INFOTABLE_H
#define INFOTABLE_H

#include <QWidget>

/// @brief 单列的宽度，调整窗口切换模式用到
/// @see src/view/admin/studentable.cpp#resizeEvent()
/// @see src/view/admin/teacherable.cpp#resizeEvent()
constexpr int TABLE_WIDGET_COLUMN_WIDTH = 100;
constexpr int TABLE_WIDGET_VERTICAL_HEADER_WIDTH = 60;

namespace Ui {
class InfoTable;
}

/// @brief 信息表抽象基类
class InfoTable : public QWidget
{
    Q_OBJECT

public:
    /// @brief 构造函数，连接一些信号和槽函数
    explicit InfoTable(QWidget *parent = nullptr);
    virtual ~InfoTable();

    /// @brief 模板方法，调用基类实现的方法
    InfoTable* init();

    /// @brief 根据成员变量sortCol排序某列
    /// @see sortCol
    virtual void sortTable();

private:
    /// @brief 添加按钮，用于管理员加一个按钮添加成员
    virtual void addBtn();

    /// @brief 设置表中每一列的名字
    /// @return 子类重写并返回一个数组，存储各列名字
    virtual QVector<QString> setColName() = 0;

    /// @brief 查询数据库并存储到内存
    virtual void loadData() = 0;

    /// @brief 将存储的数据显示到表中
    virtual void showData() = 0;

protected slots:
    /// @brief 按下搜索按钮的槽函数
    virtual void on_searchPushButton_clicked();

    /// @brief 按下刷新按钮的槽函数
    virtual void on_refreshPushButton_clicked();

    /// @brief 按下取消按钮的槽函数
    virtual void on_cancelPushButton_clicked();

protected:
    /// @brief UI
    Ui::InfoTable *ui;

    /// @brief 排序的规则，用于点击同一个按钮升降序切换
    Qt::SortOrder order;

    /// @brief 排序的列，用于刷新后需要上一次排序的列
    int sortCol;
};

#endif // INFOTABLE_H
