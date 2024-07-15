#include "FileSystem.h"
#include <filesystem>
#include <vector>
#include <algorithm>

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
            subdirs.emplace_back(QString::fromStdString(entry.path()));
        }
    }
    std::vector<std::string> temp;
    temp.reserve(subdirs.size());
    for (const auto& qString : subdirs)
    {
        temp.emplace_back(qString.toStdString());
    }
    subdirs.clear();
    subdirs.reserve(temp.size());
    //std::sort(temp.begin(), temp.end());
    //
    std::sort(temp.begin(), temp.end(), caseInsensitiveCompare);
    //
    for (const auto& string : temp)
    {
        subdirs.emplace_back(QString::fromStdString(string));
    }

    return subdirs;
}

PathProperties FileSystem::processPath(const QString &path)
{
    PathProperties result;
    fs::path entry = fs::path(path.toStdString());

    result.fullName = QString::fromStdString((std::string)entry.filename());
    result.path = path;
    if (entry.has_stem())
        result.stem = QString::fromStdString((std::string)entry.stem());
    else result.stem = QString("");
    if (entry.has_extension())
        result.extension = QString::fromStdString((std::string)entry.extension());
    else result.extension = QString("");
    result.isDirectory = fs::is_directory(entry);

    if (result.isDirectory)
        result.imageSource = QUrl("assets/icons/folder_generic.png");
    else
        result.imageSource = QUrl("assets/icons/app_generic.png");

    return result;

}

bool FileSystem::isValidDir(const QString &path)
{
    return fs::is_directory(fs::path(path.toStdString())) ? true : false;
}

QString FileSystem::gotoParentDirectory(const QString& path)
{
    return QString::fromStdString((std::string)fs::path(path.toStdString()).parent_path());

}

bool FileSystem::caseInsensitiveCompare(const std::string &a, const std::string &b)
{
    std::string lowerA = a;
    std::string lowerB = b;

    // Convert both strings to lower case for comparison
    std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
    std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);

    return lowerA < lowerB;
}
