#ifndef LISTINOLAYOUT_H
#define LISTINOLAYOUT_H

#include <QWidget>

#include <QHBoxLayout>
#include "insertlayout.h"

#include <QTableWidget>
#include <QPushButton>
#include <QString>

#include "../Modello/model.h"

class listinoLayout : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* viewTableLayout;
    insertLayout* editL;

    QTableWidget* tabellaProdotti;

    QPushButton* rimuoviBottone;
    QPushButton* modificaBottone;

public:
    explicit listinoLayout(QWidget* =nullptr);

    QPushButton* getRimuoviBottone() const;
    QPushButton* getModificaBottone() const;
    QPushButton* getSalvaModificaBottone() const;

    int getIndiceProdottoSelezionato() const;

    void aggiornaTabella(Model*);
    void formModificaProdotto(Model*);
    void salvaModificaProdotto(Model*);

public slots:
    void showModifica() const;

};

#endif // LISTINOLAYOUT_H
