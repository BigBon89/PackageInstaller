#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "enumpages.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    void SetPage(Pages Page);
    QWidget* GetPage(Pages Page);

private:
    QStackedWidget* stackedWidget;
};
#endif // MAINWINDOW_H
