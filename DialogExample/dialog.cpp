#include "dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle("各种标准对话框的实例"); //设置工程对话框标题
    //各个控件初始化
    fileBtn=new QPushButton;    //各个控件对象的初始化
    fileBtn->setText(tr("文件标准对话框实例"));
    fileLineEdit=new QLineEdit; //用来显示选择的文件名

    //添加布局管理
    mainLayout=new QGridLayout(this);   //布局设计
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);

    //添加事件关联
    connect(fileBtn,&QPushButton::clicked,this,&Dialog::showFile);

    //================标准颜色对话框==================//
    colorBtn = new QPushButton;     //创建各个控件实例
    colorBtn->setText(tr("颜色标准对话框实例"));
    colorFram = new QFrame;
    colorFram->setFrameShape(QFrame::Box);  //HLine 线 Panel 方框同Box
    colorFram->setAutoFillBackground(true);

    //添加布局管理
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFram,1,1);

    //添加事件关联
    connect(colorBtn,&QPushButton::clicked,this,&Dialog::showColor);

    //================标准字体对话框==================//
    fontBtn = new QPushButton;
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    //添加布局管理
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);

    //添加事件关联
    connect(fontBtn,&QPushButton::clicked,this,&Dialog::showFont);


}

//showFile()实现
void Dialog::showFile()
{
    //返回需要打开的文件的绝对路径，取消返回空字符
    //QString s = QFileDialog::getOpenFileName(this,"open file dialog","/default","C++ file(*.cpp);;C files(*.c);;Head files(*.h)");
    //使用这个可以同时筛选出满足条件的而不是一个每个条件单独筛选
    QString s = QFileDialog::getOpenFileName(this,"open file dialog","/default","Projects(*.c *.cpp *.h)");
    fileLineEdit->setText(s);
}

//showColor()实现
void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFram->setPalette(QPalette(c));
    }
}

//showFont()实现
void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}

Dialog::~Dialog()
{
}

