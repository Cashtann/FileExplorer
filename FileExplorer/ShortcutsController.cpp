#include "ShortcutsController.h"
#include "ShortcutInfo.h"
#include "FileSystem.h"

ShortcutsController::ShortcutsController(QObject *parent)
    : QAbstractListModel{parent}
{
    addAllShortcutItems();
}

int ShortcutsController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_shortcutList.length();
}

QVariant ShortcutsController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_shortcutList.length())
    {
        ShortcutInfo* shortcutInfo = m_shortcutList[index.row()];

        switch((ShortcutRole) role){
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

QHash<int, QByteArray> ShortcutsController::roleNames() const
{
    QHash<int, QByteArray> result;

    result[ShortcutNameRole] = "shortcutName";
    result[ShortcutPathRole] = "shortcutPath";
    result[ShortcutImageSourceRole] = "shortcutImageSource";

    return result;
}

void ShortcutsController::addShortcutItem(const QString &name, const QString &path, const QUrl &imageSource)
{
    beginInsertRows(QModelIndex(), m_shortcutList.length(), m_shortcutList.length());
    ShortcutInfo* shortcutInfo = new ShortcutInfo(this);

    shortcutInfo->setName(name);
    shortcutInfo->setPath(path);
    shortcutInfo->setImageSource(imageSource);

    m_shortcutList << shortcutInfo;

    endInsertRows();
}

void ShortcutsController::wipeAllShortcutItems()
{
    beginRemoveRows(QModelIndex(), 0, m_shortcutList.length());
    std::vector<ShortcutInfo*> toRemove;
    for (int i = 0; i < m_shortcutList.count(); i++)
    {
        toRemove.emplace_back(m_shortcutList[i]);
    }
    m_shortcutList.clear();
    for (auto& toBeRemoved : toRemove)
    {
        toBeRemoved->deleteLater();
    }
    toRemove.clear();
    endRemoveRows();
}

void ShortcutsController::addAllShortcutItems()
{
    auto folders = FileSystem::getCommonUserFolders();

    for (const auto& folder : folders)
    {
        auto f = FileSystem::processPath(folder);
        addShortcutItem(f.fullName, f.path, f.imageSource);
    }
}
