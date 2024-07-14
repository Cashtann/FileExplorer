#ifndef SHORTCUTINFO_H
#define SHORTCUTINFO_H

#include <QObject>
#include <QUrl>
#include <qqml.h>

class ShortcutInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged FINAL)
    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged FINAL)

public:
    explicit ShortcutInfo(QObject *parent = nullptr);

    QString name() const;

    QString path() const;

    QUrl imageSource() const;

    void setName(const QString &newName);

    void setPath(const QString &newPath);

    void setImageSource(const QUrl &newImageSource);

signals:
    void nameChanged();
    void pathChanged();

    void imageSourceChanged();

private:
    QString m_name = "unknown.file";
    QString m_path = "/unknown/path";
    QUrl m_imageSource = QUrl("assets/icons/app_generic.png");
};

#endif // SHORTCUTINFO_H
