#ifndef PACKAGEINSTALLER_H
#define PACKAGEINSTALLER_H

#include <QObject>

class PackageInstaller : public QObject {
    Q_OBJECT

public:
    explicit PackageInstaller(QObject* parent = nullptr);
    void InstallPackage(QString selectedFile);
    QList<QPair<QString, QString>> GetAvailablePackages();
};

#endif // PACKAGEINSTALLER_H
