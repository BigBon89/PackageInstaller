#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "pagemain.h"

PageMain::PageMain(QWidget* parent) : BasePage{parent} {
    QVBoxLayout* layoutMain = new QVBoxLayout(this);

    QLabel* labelName = new QLabel("Бал Александр", this);

    labelName->setAlignment(Qt::AlignCenter);
    layoutMain->addWidget(labelName);

    QHBoxLayout* layoutButton = new QHBoxLayout();
    QPushButton* buttonNext = new QPushButton("Далее", this);

    connect(buttonNext, &QPushButton::clicked, this, &PageMain::ButtonNextClicked);

    layoutButton->addStretch();
    layoutButton->addWidget(buttonNext);

    layoutMain->addLayout(layoutButton);
}

void PageMain::ButtonNextClicked() {
    emit navigateTo(Pages::PageInstaller);
}
