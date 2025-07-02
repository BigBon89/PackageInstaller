#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QWidget>
#include "enumpages.h"

class BasePage : public QWidget {
    Q_OBJECT

public:
    explicit BasePage(QWidget* parent = nullptr);

signals:
    void navigateTo(Pages page);
};

#endif // BASEPAGE_H
