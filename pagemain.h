#ifndef PAGEMAIN_H
#define PAGEMAIN_H

#include <QWidget>
#include "basepage.h"

class PageMain : public BasePage {
    Q_OBJECT

public:
    explicit PageMain(QWidget* parent);

private slots:
    void ButtonNextClicked();
};

#endif // PAGEMAIN_H
