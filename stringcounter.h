#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H

#include <QDebug>
#include <QString>
#include <QDir>
#include <QDirIterator>

#include <thread>
#include <mutex>



class StringCounter
{

private:
    QString m_path;
    QDir m_dir;
    uint32_t m_rowCounter;

    uint32_t countRowsInFile( QString string);
    void counterUp(uint32_t);

public:
    StringCounter(QString path);

    uint32_t getResult() const;

};

#endif // STRINGCOUNTER_H
