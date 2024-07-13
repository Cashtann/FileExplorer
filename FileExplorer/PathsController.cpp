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
