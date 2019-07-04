#ifndef SEARCHLAYOUT_H
#define SEARCHLAYOUT_H

#include <QWidget>
#include <QLayout>
#include "insertlayout.h"

#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

#include "../Modello/model.h"
#include "../Modello/Gerarchia/analcolico.h"
#include "../Modello/Gerarchia/cocktail.h"
#include "../Modello/Gerarchia/vino.h"
#include "../Modello/Gerarchia/brioche.h"
#include "../Modello/Gerarchia/panino.h"
#include "../Modello/Gerarchia/piadina.h"

class searchLayout : public QWidget {
    Q_OBJECT
private:
    QHBoxLayout* searchBarLayout;
    QVBoxLayout* viewTableLayout;
    insertLayout* editL;

    QTableWidget* tabellaProdotti;
    QComboBox* cercaParametro;
    QLineEdit* cercaValore;

    QPushButton* ricercaBottone;
    QPushButton* rimuoviBottone;
    QPushButton* modificaBottone;

    QList<int> indiciRicerca;
public:
    explicit searchLayout(QWidget* =nullptr);

    QPushButton* getCercaBottone() const;
    QPushButton* getRimuoviBottone() const;
    QPushButton* getModificaBottone() const;
    QPushButton* getSalvaModificaBottone() const;

    QString getCercaValore() const;
    int getIndiceProdottoSelezionato() const;

    void aggiornaTabella(Model*);
    void formModificaProdotto(Model*);
    void salvaModificaProdotto(Model*);

public slots:
    void setLineEdit(int);
    void showModifica() const;
};

#endif // SEARCHLAYOUT_H
