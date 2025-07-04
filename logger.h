#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QMessageBox>

class Logger {
public:
    static void Error(const QString& msg);
};

#endif // LOGGER_H
