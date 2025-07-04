#include <QFile>
#include <QTemporaryFile>
#include <QProcess>
#include <QDirIterator>
#include "packageinstaller.h"
#include "logger.h"

PackageInstaller::PackageInstaller(QObject* parent)
    : QObject{parent}
{}

void PackageInstaller::InstallPackage(QString selectedFile) {
    if (selectedFile.isEmpty()) {
        Logger::Error("File not selected");
        return;
    }

    QFile resourceFile(selectedFile);
    if (!resourceFile.open(QIODevice::ReadOnly)) {
        Logger::Error("Error when opening a resource");
        return;
    }

    QTemporaryFile tempFile;
    tempFile.setAutoRemove(false);
    tempFile.setFileTemplate("/tmp/XXXXXXXX.deb");

    if (!tempFile.open()) {
        Logger::Error("Error when creating a temporary file");
        return;
    }

    if (tempFile.write(resourceFile.readAll()) == -1) {
        Logger::Error("Error when writing to a temporary file");
        tempFile.close();
        return;
    }

    tempFile.flush();
    tempFile.close();

    resourceFile.close();

    QString script = QString("sudo dpkg -i %1; sudo apt-get install -f -y; echo 'Press Enter to exit...'; read").arg(tempFile.fileName());

    if (!QProcess::startDetached("x-terminal-emulator", QStringList() << "-e" << "bash" << "-c" << script)) {
        Logger::Error("Failed to start terminal for package installation");
    }
}

QList<QPair<QString, QString>> PackageInstaller::GetAvailablePackages() {
    QList<QPair<QString, QString>> packages;
    QDirIterator iter(":/packages/", QDirIterator::NoIteratorFlags);
    while (iter.hasNext()) {
        QString path = iter.next();
        QFileInfo fileInfo(path);
        if (!fileInfo.isDir()) {
            QString displayName = fileInfo.completeBaseName();
            packages.append(qMakePair(displayName, path));
        }
    }
    return packages;
}
