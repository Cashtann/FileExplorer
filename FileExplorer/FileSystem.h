#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <vector>
#include <QUrl>

struct PathProperties
{
    QString fullName;
    QString path;
    QString stem;
    QString extension;
    bool isDirectory;
    QUrl imageSource;
};

class FileSystem
{
public:
    FileSystem();

    static const QString directorySeparator;

    static QString getRootDirectory();

    static QString changeCurrentDirectory(const QString& currDir, const QString& newDir);

    static std::vector<QString> getSubdirectories(const QString& dir);

    static PathProperties processPath(const QString& path);

    static bool isValidDir(const QString& path);
};

#endif // FILESYSTEM_H
