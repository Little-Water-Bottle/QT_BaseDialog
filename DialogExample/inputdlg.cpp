#include "inputdlg.h"
#include <QInputDialog>

//完成各种控件的创建和槽函数的实现
//InputDlg::InputDlg 第一个表示所在作用域 第二个表示函数名（构造函数）
//:QDialog(parent)   表示将传入的参数送入给父类（继承来的类）
InputDlg::InputDlg(QWidget* parent):QDialog(parent)
{
    this->setWindowTitle(tr("标准输入对话框实例"));
    //姓名
    nameLabel1 = new QLabel;
    nameLabel1->setText(tr("姓名："));
    nameLabel2 = new QLabel;
    nameLabel2->setText(tr("张三"));    //姓名初始值
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);    //设置标签样式
    nameBtn = new QPushButton;
    nameBtn->setText(tr("修改名字"));

    //性别
    sexLabel1 = new QLabel;
    sexLabel1->setText(tr("性别："));
    sexLabel2 = new QLabel;
    sexLabel2->setText(tr("男"));    //性别的初始值
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);     //设置标签样式
    sexBtn = new QPushButton;
    sexBtn->setText(tr("修改性别"));

    //年龄
    ageLabel1 = new QLabel;
    ageLabel1->setText(tr("年龄："));
    ageLabel2 = new QLabel;
    ageLabel2->setText(tr("25"));    //年龄的初始值
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);     //设置标签样式
    ageBtn = new QPushButton;
    ageBtn->setText(tr("修改年龄"));

    //成绩
    scoreLabel1 = new QLabel;
    scoreLabel1->setText(tr("成绩："));
    scoreLabel2 = new QLabel;
    scoreLabel2->setText(tr("80"));    //成绩的初始值
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);     //设置标签样式
    scoreBtn = new QPushButton;
    scoreBtn->setText(tr("修改成绩"));

    //布局管理
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);

    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);

    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);

    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);

    //=================================
    mainLayout->setMargin(15);  //设置边框宽度
    mainLayout->setSpacing(10); //设置布局宽度

    //将按键和槽函数建立连接
    connect(nameBtn,&QPushButton::clicked,this,&InputDlg::ChangeName);
    connect(sexBtn,&QPushButton::clicked,this,&InputDlg::ChangeSex);
    connect(ageBtn,&QPushButton::clicked,this,&InputDlg::ChangeAge);
    connect(scoreBtn,&QPushButton::clicked,this,&InputDlg::ChangeScore);

    //

}

/*
nameLabel2->text()  ： 返回text属性
*/
void InputDlg::ChangeName()
{
    bool ok;
    QString text = QInputDialog::getText(this,tr("标准字符串输入对话框"),tr("请输入姓名"),QLineEdit::Normal,nameLabel2->text(),&ok);
    if(ok && !text.isEmpty())
    {
        nameLabel2->setText(text);
    }
}

void InputDlg::ChangeSex()
{
    QStringList SexItems;
    SexItems << tr("男") << tr("女"); //准备插入到组合框中的字符串列表
    bool ok;
    //SexItems:下拉列表选项
    //0:默认显示第一个选项
    //false:显示的选项不可编辑
    //ok:是否点击确认，点击确认（ok）则为true 取消（cancel）ok则赋值false
    QString SexItem = QInputDialog::getItem(this,tr("标准条目选择对话框"),
                      tr("请选择性别："),SexItems,0,false,&ok);
    if(ok && !SexItem.isEmpty())
    {
        sexLabel2->setText(SexItem);
    }
}

void InputDlg::ChangeAge()
{
    bool ok;
    int age = QInputDialog::getInt(this,tr("标准int类型输入对话框"),tr("请输入年龄"),ageLabel2->text().toInt(&ok),
                                   0,150,1,&ok);
    if(ok)
    {
        ageLabel2->setText(QString(tr("%1")).arg(age));
    }
}

void InputDlg::ChangeScore()
{
    bool ok;
    double score = QInputDialog::getDouble(this,tr("标准double类型输入对话框"),tr("请输入成绩："),
                                           scoreLabel2->text().toDouble(&ok),0,100,1,&ok);
    if(ok)
    {
        scoreLabel2->setText(QString(tr("%1")).arg(score));
    }
}
