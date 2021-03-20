#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

//添加私有成员变量
private:
    //标准文件对话框类
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;    //is a one line text edit
    QGridLayout *mainLayout;
    //标准颜色对话框类
    QPushButton *colorBtn;
    QFrame *colorFram;
    //标准字体对话框
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
//添加槽函数
private slots:
    void showFile();
    void showColor();
    void showFont();

};
#endif // DIALOG_H
