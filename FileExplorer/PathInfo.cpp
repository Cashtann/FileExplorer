#include "PathInfo.h"

PathInfo::PathInfo(QObject *parent)
    : QObject{parent}
{}


QString PathInfo::name() const
{
    return m_name;
}

QString PathInfo::path() const
{
    return m_path;
}

QUrl PathInfo::imageSource() const
{
    return m_imageSource;
}


bool PathInfo::isDirectory() const
{
    return m_isDirectory;
}


void PathInfo::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

void PathInfo::setPath(const QString &newPath)
{
    if (m_path == newPath)
        return;
    m_path = newPath;
    emit pathChanged();
}

void PathInfo::setImageSource(const QUrl &newImageSource)
{
    if (m_imageSource == newImageSource)
        return;
    m_imageSource = newImageSource;
    emit imageSourceChanged();
}

void PathInfo::setIsDirectory(bool newIsDirectory)
{
    if (m_isDirectory == newIsDirectory)
        return;
    m_isDirectory = newIsDirectory;
    emit isDirectoryChanged();
}
