#include "mainwindow.h"
#include "pagemain.h"
#include "pageinstaller.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    pageController = new PageController(stackedWidget, this);

    pageController->registerPage(new PageMain(this));
    pageController->registerPage(new PageInstaller(this));
}
