#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

void save_file(QString file_name); // write to file
void load_file(QString file_name); // load to file

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file_name = "lesson.txt";
    load_file(file_name);

    return a.exec();
}

void save_file(QString file_name) // write to file
{
    QFile file(file_name);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
    }
    QTextStream stream(&file);
    stream.seek(file.size()); // always seek to the end of text stream to append the next string of text
    stream << "text file saved";
    stream.flush();
    file.close();
}

void load_file(QString file_name) // load to file
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return;
    }
    else
    {
        qInfo() << "Opened file";
        QTextStream stream(&file);
        stream.seek(0);
        while(!stream.atEnd())
        {
            qInfo() << stream.readLine();
        }
        qInfo() << "Load file success";
    }
    file.close();
}
