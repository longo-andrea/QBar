#include "insertformexception.h"

#include <QString>

insertFormException::insertFormException(QString warningMsg) : warning(warningMsg) {}

QString insertFormException::getWarning() const {
    return warning;
}
