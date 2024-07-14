#ifndef PATHSCONTROLLER_H
#define PATHSCONTROLLER_H

#include <QObject>
//#include <QAbstractListModel>
#include "FileSystem.h"

//class ShortcutInfo;

class PathsController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentDirectory READ currentDirectory NOTIFY currentDirectoryChanged FINAL)
public:
    enum ShortcutRole {
        ShortcutNameRole = Qt::UserRole + 1,
        ShortcutPathRole,
        ShortcutImageSourceRole
    };

    explicit PathsController(QObject *parent = nullptr);

    QString currentDirectory() const;

    void setCurrentDirectory(const QString &newCurrentDirectory);
    /*
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    */

public slots:
    void changeCurrentDirectory(const QString& newPath);

    void printCurrentDirectory();

    void printCurrentSubdirectories();

signals:
    void currentDirectoryChanged();
private:
    QString m_currentDirectory = FileSystem::getRootDirectory();

    //QList<ShortcutInfo*> m_shortcutList;

};

#endif // PATHSCONTROLLER_H
