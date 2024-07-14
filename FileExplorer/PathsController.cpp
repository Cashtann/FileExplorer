#include "PathsController.h"

#include "FileSystem.h"
#include <QDebug>
#include <vector>


PathsController::PathsController(QObject *parent)
    : QObject{parent}
{}

QString PathsController::currentDirectory() const
{
    return m_currentDirectory;
}

void PathsController::setCurrentDirectory(const QString &newCurrentDirectory)
{
    if (m_currentDirectory == newCurrentDirectory)
        return;
    m_currentDirectory = newCurrentDirectory;
    emit currentDirectoryChanged();
}
/*
int PathsController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_shortcutList.length();
}

QVariant PathsController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_shortcutList.length())
    {
        ShortcutInfo* shortcutInfo = m_shortcutList[index.row()];

        switch((ShortcutRole)role) {
        case ShortcutNameRole:
            return shortcutInfo->name();
        case ShortcutPathRole:
            return shortcutInfo->path();
        case ShortcutImageSourceRole:
            return shortcutInfo->imageSource();
        }
    }

    return {};
}

QHash<int, QByteArray> PathsController::roleNames() const
{
    QHash<int, QByteArray> result;

    result[ShortcutNameRole] = "name";
    result[ShortcutPathRole] = "path";
    result[ShortcutImageSourceRole] = "imageSource";

    return result;
}
*/

void PathsController::printCurrentDirectory()
{
    qDebug() << "[Debug] Current directory: " << m_currentDirectory;
}

void PathsController::printCurrentSubdirectories()
{
    qDebug() << "Current subdirectories: ";
    for (const auto& subdir : FileSystem::getSubdirectories(m_currentDirectory))
    {
        qDebug() << subdir;
    }
}

void PathsController::changeCurrentDirectory(const QString& newPath)
{
    m_currentDirectory = FileSystem::changeCurrentDirectory(m_currentDirectory, newPath);
    emit currentDirectoryChanged();
}
