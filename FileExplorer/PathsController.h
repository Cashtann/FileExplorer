#ifndef PATHSCONTROLLER_H
#define PATHSCONTROLLER_H

#include <QObject>
#include "FileSystem.h"

class PathsController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentDirectory READ currentDirectory NOTIFY currentDirectoryChanged FINAL)
public:
    explicit PathsController(QObject *parent = nullptr);

    QString currentDirectory() const;

    void setCurrentDirectory(const QString &newCurrentDirectory);


public slots:
    void changeCurrentDirectory(const QString& newPath);

    void printCurrentDirectory();

    void printCurrentSubdirectories();

signals:
    void currentDirectoryChanged();
private:
    QString m_currentDirectory = FileSystem::getRootDirectory();
};

#endif // PATHSCONTROLLER_H
