#include "FilesController.h"
#include "PathInfo.h"
#include "FileSystem.h"
#include <QUrl>

FilesController::FilesController(QObject *parent)
    : QAbstractListModel{parent}
{
    QString name = "dupa.png";
    QString path = "/home/cashtan";
    QUrl imageSource = QUrl("assets/icons/folder_generic.png");
    bool isFile = true;
    addPathItem(name, path, imageSource, isFile);
    addPathItem(name, path, imageSource, isFile);
    addPathItem(name, path, imageSource, isFile);
    addPathItem(name, path, imageSource, isFile);

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
        case PathItemIsFileRole:
            return pathInfo->isFile();
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
    result[PathItemIsFileRole] = "pathItemIsFile";

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

void FilesController::addPathItem(const QString &name, const QString &path, const QUrl &imageSource, const bool &isFile)
{
    beginInsertRows(QModelIndex(), m_pathItemList.length(), m_pathItemList.length());
    PathInfo* pathInfo = new PathInfo(this);

    pathInfo->setName(name);
    pathInfo->setPath(path);
    pathInfo->setImageSource(imageSource);
    pathInfo->setIsFile(isFile);

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

void FilesController::refreshAllPathItems()
{

}
