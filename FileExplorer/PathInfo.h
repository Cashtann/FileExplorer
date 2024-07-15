#ifndef PATHINFO_H
#define PATHINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>


class PathInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged FINAL)
    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged FINAL)
    Q_PROPERTY(bool isDirectory READ isDirectory WRITE setIsDirectory NOTIFY isDirectoryChanged FINAL)

public:

    explicit PathInfo(QObject *parent = nullptr);

    QString name() const;
    QString path() const;
    QUrl imageSource() const;

    void setName(const QString &newName);
    void setPath(const QString &newPath);
    void setImageSource(const QUrl &newImageSource);

    bool isDirectory() const;
    void setIsDirectory(bool newIsDirectory);

signals:

    void nameChanged();
    void pathChanged();
    void imageSourceChanged();
    void isDirectoryChanged();

private:

    QString m_name = "[error] not found";
    QString m_path = "/error/not/found";
    QUrl m_imageSource = QUrl("assets/icons/error.png");
    bool m_isDirectory = false;
};

#endif // PATHINFO_H
