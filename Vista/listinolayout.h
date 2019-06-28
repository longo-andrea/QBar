#ifndef LISTINOLAYOUT_H
#define LISTINOLAYOUT_H

#include <QWidget>

#include <QTableWidget>
#include <QPushButton>
#include <QString>

#include "../Modello/model.h"

class listinoLayout : public QWidget {
    Q_OBJECT
private:
   QTableWidget* tabellaProdotti;

public:
    explicit listinoLayout(QWidget* =nullptr);

    void aggiornaTabella(Model*);

};

#endif // LISTINOLAYOUT_H
