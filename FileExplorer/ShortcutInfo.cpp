#include "ShortcutInfo.h"

ShortcutInfo::ShortcutInfo(QObject *parent)
    : QObject{parent}
{}

QString ShortcutInfo::name() const
{
    return m_name;
}

QString ShortcutInfo::path() const
{
    return m_path;
}

QUrl ShortcutInfo::imageSource() const
{
    return m_imageSource;
}

void ShortcutInfo::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

void ShortcutInfo::setPath(const QString &newPath)
{
    if (m_path == newPath)
        return;
    m_path = newPath;
    emit pathChanged();
}

void ShortcutInfo::setImageSource(const QUrl &newImageSource)
{
    if (m_imageSource == newImageSource)
        return;
    m_imageSource = newImageSource;
    emit imageSourceChanged();
}
