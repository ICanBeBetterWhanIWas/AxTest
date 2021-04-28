#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QTextStream>

#include "stringcounter.h"

QTextStream cin(stdin);

QString getPath()
{

    qDebug() << "Absolute path('N' or 'n' for exit) >>" << endl;
    QString path = cin.readLine();
    //qDebug() << QString(path) << endl;

    if(path == "n" || path == "N")
    {
        exit(0);
    }

    /*if(path == "0")
    {
        return "C:/Users/User1/Desktop/Test";
    }*/

    if(QFile(path).isReadable())
    {
        return path;
    }
    else
    {
        qDebug() << "Can not open:" << path << endl;
        getPath();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    StringCounter sc{getPath()};
    qDebug() << sc.getResult() << endl;

    return 0;
    //return a.exec();
}
