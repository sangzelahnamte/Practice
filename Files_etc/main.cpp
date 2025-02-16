#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

void save_file(QString file_name); // write to file
void load_file(QString file_name); // load to file

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file_name = "lesson.txt";
    save_file(file_name);
    load_file(file_name);

    return a.exec();
}

void save_file(QString file_name) // write to file
{
    QFile file(file_name);
    if(!file.open(QIODevice::WriteOnly)) // if it cannot open
    {
        qInfo() << file.errorString();
        file.close();
        return;
    }
    else
    {
        QTextStream stream(&file);
        stream.seek(file.size()); // always seek to the end of text stream to append the next string of text
        QString text = "some text that gets added\n";
        stream << text;
        file.write(text.toUtf8());
        stream.flush();
    }
    file.close();
}

void load_file(QString file_name) // load to file
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        file.close();
        return;
    }
    else
    {
        qInfo() << "Opened file";
        QTextStream stream(&file);
        stream.seek(0);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            qInfo() << line;
        }
        qInfo() << "Load file success";
    }
    file.close();
}
