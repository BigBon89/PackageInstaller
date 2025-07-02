#include "pageinstaller.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

PageInstaller::PageInstaller(QWidget* parent) : BasePage{parent} {
    QVBoxLayout* layoutMain = new QVBoxLayout(this);

    QLabel* labelText = new QLabel("Текст", this);

    labelText->setAlignment(Qt::AlignCenter);
    layoutMain->addWidget(labelText);

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

}
