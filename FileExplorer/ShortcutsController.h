#ifndef SHORTCUTSCONTROLLER_H
#define SHORTCUTSCONTROLLER_H

#include <QObject>
#include <qqml.h>
#include <QAbstractListModel>

class ShortcutsController : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ShortcutRole {
        ShortcutNameRole = Qt::UserRole + 1,
        ShortcutPathRole,
        ShortcutImageSourceRole
    };

    explicit ShortcutsController(QObject *parent = nullptr);

signals:

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // SHORTCUTSCONTROLLER_H
