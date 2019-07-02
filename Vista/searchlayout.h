#ifndef SEARCHLAYOUT_H
#define SEARCHLAYOUT_H

#include <QWidget>
#include <QLayout>

#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

#include "../Modello/model.h"


class searchLayout : public QWidget {
    Q_OBJECT
private:
    QHBoxLayout* searchBarLayout;
    QVBoxLayout* viewTableLayout;

    QTableWidget* tabellaProdotti;

    QComboBox* cercaParametro;
    QLineEdit* cercaValore;

    QPushButton* ricercaBottone;
    QPushButton* rimuoviBottone;
    QPushButton* modificaBottone;

    QList<int> indiciRicerca; // contiene gli indici degli oggetti trovati tramite la ricerca
public:
    explicit searchLayout(QWidget* =nullptr);

    QPushButton* getCercaBottone() const;
    QPushButton* getRimuoviBottone() const;
    QString getCercaValore() const;

    int getIndiceProdottoSelezionato() const;

    void aggiornaTabella(Model*);
    void pulisciTabella();

public slots:
    void setLineEdit(int);
};

#endif // SEARCHLAYOUT_H
