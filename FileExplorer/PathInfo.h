#ifndef PATHINFO_H
#define PATHINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>

class PathInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString path READ path NOTIFY pathChanged FINAL)
    Q_PROPERTY(QUrl imageSource READ imageSource NOTIFY imageSourceChanged FINAL)
    Q_PROPERTY(bool isFile READ isFile NOTIFY isFileChanged FINAL)

public:
    explicit PathInfo(QObject *parent = nullptr);

    QString name() const;

    QString path() const;

    QUrl imageSource() const;

    bool isFile() const;

signals:
    void nameChanged();
    void pathChanged();
    void imageSourceChanged();
    void isFileChanged();

private:
    QString m_name;
    QString m_path;
    QUrl m_imageSource;
    bool m_isFile;
};

#endif // PATHINFO_H
