#include <QDebug>
#include <QDir>

int main()
{
    qDebug() << "Using CMake runing Qt app.";
    qDebug() << "Current directory is : " << QDir::currentPath();

    return 0;
}
