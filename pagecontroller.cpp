#include "pagecontroller.h"

PageController::PageController(QStackedWidget* stacked, QObject* parent)
    : stackedWidget{stacked}, QObject{parent}
{

}

void PageController::registerPage(BasePage* page) {
    stackedWidget->addWidget(page);
    connect(page, &BasePage::navigateTo, this, &PageController::onNavigateTo);
}

void PageController::onNavigateTo(Pages page) {
    stackedWidget->setCurrentIndex(static_cast<int>(page));
}
