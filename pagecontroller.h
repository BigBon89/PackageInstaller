#ifndef PAGECONTROLLER_H
#define PAGECONTROLLER_H

#include <QObject>
#include <QStackedWidget>
#include "enumpages.h"
#include "basepage.h"

class PageController : public QObject {
    Q_OBJECT

public:
    explicit PageController(QStackedWidget* stacked, QObject* parent = nullptr);
    void registerPage(BasePage* page);

private slots:
    void onNavigateTo(Pages page);

private:
    QStackedWidget* stackedWidget;
};

#endif // PAGECONTROLLER_H
