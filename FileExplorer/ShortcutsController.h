#ifndef SHORTCUTSCONTROLLER_H
#define SHORTCUTSCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>
#include <QUrl>

class ShortcutInfo;

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

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:
    void addShortcutItem(const QString& name,
                         const QString& path,
                         const QUrl& imageSource);
    void wipeAllShortcutItems();
    void addAllShortcutItems();

signals:



private:
    QList<ShortcutInfo*> m_shortcutList;
};

#endif // SHORTCUTSCONTROLLER_H
