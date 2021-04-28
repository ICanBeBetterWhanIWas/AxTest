#include "stringcounter.h"
#include <fstream>

std::mutex mtx;

StringCounter::StringCounter(QString path) : m_path(path), m_rowCounter(0)
{
     QDirIterator iter(m_path ,QStringList() <<"*.txt", QDir::Files, QDirIterator::Subdirectories );
     while (iter.hasNext())
     {
         std::thread t(&StringCounter::countRowsInFile, this, iter.next() );
         t.join();
     }
}

uint32_t StringCounter::countRowsInFile( QString path)
{
    std::ifstream file(path.toStdString());

        if (!file.is_open())
        {
            qDebug() << "Error opening file:" << path << endl;
            return 0;
        }

        uint32_t counter = 0;
        while(file.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'))
            counter++;
        file.close();

        //qDebug() << counter << endl;
        counterUp(counter);
        return counter;

}

uint32_t StringCounter::getResult() const
{
    return m_rowCounter;
}

void StringCounter::counterUp(uint32_t add)
{
    std::lock_guard<std::mutex>lock (mtx);
    m_rowCounter+= add;
    //qDebug() << m_rowCounter << endl;
}

