#include "FilesController.h"
#include "PathInfo.h"
#include "FileSystem.h"
#include <QUrl>
#include <QDebug>

FilesController::FilesController(QObject *parent)
    : QAbstractListModel{parent}
{
    setCurrentDirectory(FileSystem::getRootDirectory());
    qDebug() << "Current directory: " << m_currentDirectory;
    addAllCurrentPathItems();

}

int FilesController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_pathItemList.length();
}

QVariant FilesController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_pathItemList.length())
    {
        PathInfo* pathInfo = m_pathItemList[index.row()];

        switch((PathItemRole) role){
        case PathItemNameRole:
            return pathInfo->name();
        case PathItemPathRole:
            return pathInfo->path();
        case PathItemImageSourceRole:
            return pathInfo->imageSource();
        case PathItemIsDirectoryRole:
            return pathInfo->isDirectory();
        }
    }
    return {};
}

QHash<int, QByteArray> FilesController::roleNames() const
{
    QHash<int, QByteArray> result;

    result[PathItemNameRole] = "pathItemName";
    result[PathItemPathRole] = "pathItemPath";
    result[PathItemImageSourceRole] = "pathItemImageSource";
    result[PathItemIsDirectoryRole] = "pathItemIsDirectory";

    return result;
}

QString FilesController::currentDirectory() const
{
    return m_currentDirectory;
}

void FilesController::setCurrentDirectory(const QString &newCurrentDirectory)
{
    if (m_currentDirectory == newCurrentDirectory)
        return;
    m_currentDirectory = newCurrentDirectory;
    emit currentDirectoryChanged();
}

void FilesController::addPathItem(const QString &name, const QString &path, const QUrl &imageSource, const bool &isDirectory)
{
    beginInsertRows(QModelIndex(), m_pathItemList.length(), m_pathItemList.length());
    PathInfo* pathInfo = new PathInfo(this);

    pathInfo->setName(name);
    pathInfo->setPath(path);
    pathInfo->setImageSource(imageSource);
    pathInfo->setIsDirectory(isDirectory);

    m_pathItemList << pathInfo;

    endInsertRows();
}

void FilesController::wipeAllPathItems()
{
    beginRemoveRows(QModelIndex(), 0, m_pathItemList.length());
    std::vector<PathInfo*> toRemove;
    for (int i = 0; i < m_pathItemList.count(); i++)
    {
        toRemove.emplace_back(m_pathItemList[i]);
    }
    m_pathItemList.clear();
    for (auto& toBeRemoved : toRemove)
    {
        toBeRemoved->deleteLater();
    }
    toRemove.clear();
    endRemoveRows();
}

void FilesController::addAllCurrentPathItems()
{
    auto allCurrentSubdirs = FileSystem::getSubdirectories(m_currentDirectory);
    for (const auto& subdir : allCurrentSubdirs)
    {
        auto f = FileSystem::processPath(subdir);
        addPathItem(f.fullName, f.path, f.imageSource, f.isDirectory);
    }
}

void FilesController::refreshAllPathItems(const QString& newDir)
{
    wipeAllPathItems();
    setCurrentDirectory(newDir);
    addAllCurrentPathItems();
}

void FilesController::changeDirectory(const QString &newDir)
{
    if (FileSystem::isValidDir(newDir))
    {
        refreshAllPathItems(newDir);
    }
}

void FilesController::goBack()
{
    refreshAllPathItems(FileSystem::gotoParentDirectory(m_currentDirectory));
    emit currentDirectoryChanged();
}
