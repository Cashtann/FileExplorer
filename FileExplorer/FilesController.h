#ifndef FILESCONTROLLER_H
#define FILESCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>


class PathInfo;

class FilesController : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QString currentDirectory READ currentDirectory WRITE setCurrentDirectory NOTIFY currentDirectoryChanged FINAL)

public:
    enum PathItemRole {
        PathItemNameRole = Qt::UserRole + 1,
        PathItemPathRole,
        PathItemImageSourceRole,
        PathItemIsDirectoryRole
    };


    explicit FilesController(QObject *parent = nullptr);
    ~FilesController();

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    QString currentDirectory() const;
    void setCurrentDirectory(const QString &newCurrentDirectory);

public slots:
    void addPathItem(const QString& name,
                     const QString& path,
                     const QUrl& imageSource,
                     const bool& isFile);
    void wipeAllPathItems();
    void addAllCurrentPathItems();
    void refreshAllPathItems(const QString& newDir);
    void refreshAllPathItems();
    void changeDirectory(const QString& newDir);
    void goBack();
    void search(const QString& phrase, const QString& path);


signals:
    void currentDirectoryChanged();

private:
    QList<PathInfo*> m_pathItemList;

    QString m_currentDirectory;


};

#endif // FILESCONTROLLER_H
