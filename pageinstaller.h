#ifndef PAGEINSTALLER_H
#define PAGEINSTALLER_H

#include <QWidget>
#include <QComboBox>
#include "basepage.h"
#include "packageinstaller.h"

class PageInstaller : public BasePage {
    Q_OBJECT

public:
    explicit PageInstaller(QWidget* parent);

private slots:
    void ButtonBackClicked();
    void ButtonInstallClicked();

private:
    PackageInstaller* packageInstaller;
    QComboBox* comboBox;
};

#endif // PAGEINSTALLER_H
