#include "FilesController.h"
#include "PathInfo.h"
#include "FileSystem.h"
#include <QUrl>
#include <QDebug>

FilesController::FilesController(QObject *parent)
    : QAbstractListModel{parent}
{
    m_currentDirectory = FileSystem::getRootDirectory();
    qDebug() << "Current directory: " << m_currentDirectory;
    addAllCurrentPathItems();
    // QString name = "dupa.png";
    // QString path = "/home/cashtan";
    // QUrl imageSource = QUrl("assets/icons/folder_generic.png");
    // bool isFile = true;
    // addPathItem(name, path, imageSource, isFile);
    // addPathItem(name, path, imageSource, isFile);
    // addPathItem(name, path, imageSource, isFile);
    // addPathItem(name, path, imageSource, isFile);

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
    if (!m_pathItemList.isEmpty())
    {
        m_pathItemList.clear();
    }
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

void FilesController::refreshAllPathItems()
{
    wipeAllPathItems();

}
