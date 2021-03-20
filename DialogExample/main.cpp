#include "dialog.h"
#include <QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());        //加入以便能显示中文
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());  //被舍弃了

/*  Changes to QTextCodec
    QTextCodec::codecForCStrings() and QTextCodec::setCodecForCStrings() are removed as they were creating uncertainty/bugs in using QString easily and (to a lesser extent) performance issues.
    QTextCodec::codecForTr() and QTextCodec::setCodecForTr() are removed.
*/
    Dialog w;
    w.show();
    return a.exec();
}
