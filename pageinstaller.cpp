#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "pageinstaller.h"

PageInstaller::PageInstaller(QWidget* parent) : BasePage{parent} {
    packageInstaller = new PackageInstaller(this);

    QVBoxLayout* layoutMain = new QVBoxLayout(this);

    comboBox = new QComboBox(this);
    layoutMain->addWidget(comboBox);

    QList<QPair<QString, QString>> packages = packageInstaller->GetAvailablePackages();
    for (int index = 0; index < packages.size(); index++) {
        const auto& pkg = packages.at(index);
        comboBox->addItem(pkg.first, pkg.second);
    }

    QHBoxLayout* layoutButton = new QHBoxLayout();
    QPushButton* buttonBack = new QPushButton("Назад", this);
    QPushButton* buttonInstall = new QPushButton("Установить", this);

    connect(buttonBack, &QPushButton::clicked, this, &PageInstaller::ButtonBackClicked);
    connect(buttonInstall, &QPushButton::clicked, this, &PageInstaller::ButtonInstallClicked);

    layoutButton->addWidget(buttonBack);
    layoutButton->addStretch();
    layoutButton->addWidget(buttonInstall);

    layoutMain->addLayout(layoutButton);
}

void PageInstaller::ButtonBackClicked() {
    emit navigateTo(Pages::PageMain);
}

void PageInstaller::ButtonInstallClicked() {
    QString selectedFile = comboBox->currentData().toString();
    packageInstaller->InstallPackage(selectedFile);
}
