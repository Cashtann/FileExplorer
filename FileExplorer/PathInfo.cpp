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

bool PathInfo::isFile() const
{
    return m_isFile;
}
