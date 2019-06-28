#ifndef INSERTFORMEXCEPTION_H
#define INSERTFORMEXCEPTION_H

#include <QString>

class insertFormException {
private:
    QString warning;

public:
    insertFormException(QString ="Verifica tutti i campi.");

    QString getWarning() const;
};

#endif // INSERTFORMEXCEPTION_H
