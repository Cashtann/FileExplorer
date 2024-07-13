#include "FileSystem.h"
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

QString const FileSystem::directorySeparator = QString((QChar)std::filesystem::path::preferred_separator);

FileSystem::FileSystem() {}

QString FileSystem::getRootDirectory()
{
    return QString::fromStdString((std::string)fs::current_path().root_directory());
}

QString FileSystem::changeCurrentDirectory(const QString &currDir, const QString &newDir)
{
    QString newPath = currDir + FileSystem::directorySeparator + newDir;
    if (fs::is_directory((fs::path)newPath.toStdString()))
    {
        return newPath;
    }
    else
    {
        return currDir;
    }
}

std::vector<QString> FileSystem::getSubdirectories(const QString& dir)
{
    std::vector<QString> subdirs;
    if (fs::is_directory((fs::path)dir.toStdString()))
    {
        for (const auto& entry : fs::directory_iterator((fs::path)dir.toStdString()))
        {
            subdirs.emplace_back(QString::fromStdString(entry.path().filename()));
        }
    }
    return subdirs;
}
