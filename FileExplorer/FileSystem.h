#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <vector>
#include <QUrl>
#include <string>
#include <filesystem>


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

    static QString gotoParentDirectory(const QString& path);

    static bool caseInsensitiveCompare(const std::string &a, const std::string &b);

    static std::filesystem::path getXDGUserDir(const std::string &key, const std::filesystem::path &defaultPath);

    static std::vector<QString> getCommonUserFolders();

    static QString getHomeDir();
};

#endif // FILESYSTEM_H
