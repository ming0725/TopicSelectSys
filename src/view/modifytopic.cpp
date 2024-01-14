#include "modifytopic.h"
#include "ui_modifytopic.h"
#include <QException>
#include <QMessageBox>

ModifyTopic::ModifyTopic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyTopic)
{
    ui->setupUi(this);
    connect(ui->cancelPushButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->commitPushButton, &QPushButton::clicked, this, &ModifyTopic::onCommitBtnClicked);
}

ModifyTopic::~ModifyTopic()
{
    delete ui;
}

ModifyTopic::ModifyTopic(Topic topic, QWidget *parent)
    : ModifyTopic(parent)
{
    this->topic = topic;
    ui->tpidLineEdit->setText(topic.getId());
    ui->maxNumSpinBox->setValue(topic.getMax());
    ui->titleLineEdit->setText(topic.getTitle());
    ui->descTextEdit->setText(topic.getDesc());
    ui->reqTextEdit->setText(topic.getRequirement());
    callback = [this](){
        topicModel.update(this->topic);
        QMessageBox::warning(this, "提示", "修改成功");
    };
}

void ModifyTopic::onCommitBtnClicked()
{
    topic.setId(ui->tpidLineEdit->text());
    topic.setTitle(ui->titleLineEdit->text());
    topic.setMax(ui->maxNumSpinBox->value());
    topic.setDesc(ui->descTextEdit->toPlainText());
    topic.setRequirement(ui->reqTextEdit->toPlainText());
    try
    {
        callback();
        accept();
    }
    catch (const QException& e)
    {
        QMessageBox::warning(this, "提示", e.what());
    }
    catch (...)
    {
        QMessageBox::warning(this, "提示", "未知错误！");
    }
}

ModifyTopic::ModifyTopic(Teacher teacher, QWidget *parent)
    :  ModifyTopic(parent)
{
    this->teacher = teacher;
    callback = [this](){
        this->topic.setTeacherId(this->teacher.getId());
        this->topicModel.insert(this->topic);
        QMessageBox::warning(this, "提示", "添加成功");
    };
}
