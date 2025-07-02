#include "mainwindow.h"
#include "pagemain.h"
#include "pageinstaller.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);

    PageMain* pageMain = new PageMain(this);
    PageInstaller* pageInstaller = new PageInstaller(this);

    stackedWidget->addWidget(pageMain);
    stackedWidget->addWidget(pageInstaller);

    this->setCentralWidget(stackedWidget);
}

void MainWindow::SetPage(Pages page) {
    stackedWidget->setCurrentIndex(static_cast<int>(page));
}

QWidget* MainWindow::GetPage(Pages page) {
    return stackedWidget->widget(static_cast<int>(page));
}
