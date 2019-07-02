#ifndef LISTINOLAYOUT_H
#define LISTINOLAYOUT_H

#include <QWidget>

#include <QHBoxLayout>

#include <QTableWidget>
#include <QPushButton>
#include <QString>

#include "../Modello/model.h"

class listinoLayout : public QWidget {
    Q_OBJECT
private:
    QTableWidget* tabellaProdotti;

    QPushButton* rimuoviBottone;

public:
    explicit listinoLayout(QWidget* =nullptr);

    QPushButton* getRimuoviBottone() const;
    int getIndiceProdottoSelezionato() const;

    void aggiornaTabella(Model*);

};

#endif // LISTINOLAYOUT_H
