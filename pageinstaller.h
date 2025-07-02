#ifndef PAGEINSTALLER_H
#define PAGEINSTALLER_H

#include <QWidget>
#include "basepage.h"

class PageInstaller : public BasePage {
    Q_OBJECT

public:
    explicit PageInstaller(QWidget* parent);

private slots:
    void ButtonBackClicked();
    void ButtonInstallClicked();
};

#endif // PAGEINSTALLER_H
