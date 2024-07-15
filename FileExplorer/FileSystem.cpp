#include "FileSystem.h"
#include <algorithm>
#include <fstream>
#include <sstream>

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
        //char pathFirstChar = ((std::string)fs::path(qString.toStdString()).filename())[0];
        if (std::isalnum(((std::string)fs::path(qString.toStdString()).filename())[0])) // Hides hidden directories (e.g. ".gitignore")
        {
            temp.emplace_back(qString.toStdString());
        }
        //temp.emplace_back(qString.toStdString());
    }
    subdirs.clear();
    subdirs.reserve(temp.size());

    std::sort(temp.begin(), temp.end(), caseInsensitiveCompare);

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
    // Check if the first character of the strings are alphanumeric
    std::string realA = (std::string)fs::path(a).filename();
    std::string realB = (std::string)fs::path(b).filename();

    bool aIsAlnum = std::isalnum(realA[0]);
    bool bIsAlnum = std::isalnum(realB[0]);

    if (aIsAlnum && bIsAlnum) {
        // If both are alphanumeric, compare normally (case-insensitive)
        std::string lowerA = realA;
        std::string lowerB = realB;
        std::transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        std::transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    }

    if (aIsAlnum) {
        // If only 'a' is alphanumeric, it should come first
        return true;
    }

    if (bIsAlnum) {
        // If only 'b' is alphanumeric, it should come first
        return false;
    }

    // If both start with special characters, compare normally
    return realA < realB;
}

std::filesystem::__cxx11::path FileSystem::getXDGUserDir(const std::string &key, const std::filesystem::__cxx11::path &defaultPath)
{
    const char *homeDir = std::getenv("HOME");
    if (!homeDir)
        return defaultPath;

    std::ifstream userDirsFile(fs::path(homeDir) / ".config/user-dirs.dirs");
    if (!userDirsFile.is_open())
        return defaultPath;

    std::string line;
    while (std::getline(userDirsFile, line))
    {
        if (line.find(key) != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            while (iss >> token)
            {
                if (token.find("$HOME") != std::string::npos)
                {
                    std::string path = token.substr(token.find('=') + 2);
                    path.pop_back();                           // Remove the trailing double quote
                    return fs::path(homeDir) / path.substr(6); // Remove "$HOME/"
                }
            }
        }
    }
    return defaultPath;
}

std::vector<QString> FileSystem::getCommonUserFolders()
{
    std::vector<QString> folders;

    const char *homeDir = std::getenv("HOME");
    if (homeDir)
    {
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_DESKTOP_DIR", fs::path(homeDir) / "Desktop")));
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_DOCUMENTS_DIR", fs::path(homeDir) / "Documents")));
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_DOWNLOAD_DIR", fs::path(homeDir) / "Downloads")));
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_PICTURES_DIR", fs::path(homeDir) / "Pictures")));
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_MUSIC_DIR", fs::path(homeDir) / "Music")));
        folders.push_back(QString::fromStdString(getXDGUserDir("XDG_VIDEOS_DIR", fs::path(homeDir) / "Videos")));
    }

    return folders;
}

QString FileSystem::getHomeDir()
{
    std::string homeDir = std::getenv("HOME");
    return QString::fromStdString(homeDir);
}
