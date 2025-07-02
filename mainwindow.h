#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "pagecontroller.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    QStackedWidget* stackedWidget;
    PageController* pageController;
};
#endif // MAINWINDOW_H
