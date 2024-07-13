#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <vector>

class FileSystem
{
public:
    FileSystem();

    static const QString directorySeparator;

    static QString getRootDirectory();

    static QString changeCurrentDirectory(const QString& currDir, const QString& newDir);

    static std::vector<QString> getSubdirectories(const QString& dir);
};

#endif // FILESYSTEM_H
