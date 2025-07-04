#include "logger.h"

void Logger::Error(const QString& msg) {
    QMessageBox::critical(nullptr, "Error", msg);
}
