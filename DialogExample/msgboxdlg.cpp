#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg(QWidget *parent):QDialog(parent)
{
    this->setWindowTitle(tr("标准消息对话框实例"));    //设置对话框的标题
    //按钮初始化
    label = new QLabel;
    label->setText(tr("请选择一种消息框"));
    questionBtn = new QPushButton;
    questionBtn->setText(tr("QustionMsg"));
    informationBtn = new QPushButton;
    informationBtn->setText(tr("InformationMsg"));
    warningBtn = new QPushButton;
    warningBtn->setText(tr("WaringMsg"));
    criticalBtn = new QPushButton;
    criticalBtn->setText(tr("CriticalMsg"));
    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("AboutBtnMsg"));
    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("AboutQtBtnMsg"));

    //布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    //事件关联
    connect(questionBtn,&QPushButton::clicked,this,&MsgBoxDlg::showQuestionMsg);
    connect(informationBtn,&QPushButton::clicked,this,&MsgBoxDlg::showInformationMsg);
    connect(warningBtn,&QPushButton::clicked,this,&MsgBoxDlg::showWarningMsg);
    connect(criticalBtn,&QPushButton::clicked,this,&MsgBoxDlg::showCriticalMsg);
    connect(aboutBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutMsg);
    connect(aboutQtBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutQtMsg);

}




void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Questioon Message Box"));
    switch(QMessageBox::question(this,tr("Question消息框"),tr("您现在已经修改完成，是否要结束程序"),
                                 QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
        case QMessageBox::Ok:
            label->setText("Question button/OK");
        break;
        case QMessageBox::Cancel:
            label->setText("Question buton/Cancel");
        default:
            break;
    }
}

void MsgBoxDlg::showInformationMsg()
{
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this,tr("Information消息框"),
                             tr("这是Information消息框测试，欢迎您！")/*,QMessageBox::Ok|QMessageBox::Cancel*/);
    return;
}

void MsgBoxDlg::showWarningMsg()
{
    label->setText(tr("Waring Message Box"));
    switch(QMessageBox::warning(this,tr("Warning消息框"),
                                tr("您修改的内容还未保存，是否要保存对文档的修改?"),
                                QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
                                QMessageBox::Save))
    {
        case QMessageBox::Save:
            label->setText(tr("Waring Button /Save"));break;
        case QMessageBox::Discard:
            label->setText(tr("Waring Button /Discard"));break;
        case QMessageBox::Cancel:
            label->setText(tr("Waring Button /Cancel"));break;
        default:
            break;
    }
    return;
}

void MsgBoxDlg::showCriticalMsg()
{
    label->setText(tr("Critical Message Box"));
    QMessageBox::critical(this,tr("Critical 消息框"),tr("这个是一个Critical消息测试！"));
    return;
}

void MsgBoxDlg::showAboutMsg()
{
    label->setText(tr("About Message Box"));
    QMessageBox::about(this,tr("About 消息框"),tr("这是一个 About 消息框测试!"));
    return;
}

void MsgBoxDlg::showAboutQtMsg()
{
    label->setText(tr("About Qt Message Box"));
    QMessageBox::aboutQt(this,tr("About Qt消息框"));
    return;
}
