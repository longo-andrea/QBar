#ifndef CONTROLLER_H
#define CONTROLLERH

#include <QWidget>
#include <QMainWindow>
#include <QCloseEvent>

#include <QLayout>
#include "searchlayout.h"
#include "indexlayout.h"
#include "insertlayout.h"
#include "listinolayout.h"

#include <QMenuBar>

#include "../Modello/model.h"

class Controller : public QWidget {
    Q_OBJECT
private:
    QString fileData;

    Model* modello;

    QVBoxLayout* mainLayout;
    QMenuBar* menuBar;
    searchLayout* searchL;
    indexLayout* indexL;
    insertLayout* insertL;
    listinoLayout* listinoL;

    virtual void closeEvent (QCloseEvent*) override;
public:
    explicit Controller(QWidget * =0);
    ~Controller() override;

public slots:
    void showIndexLayout() const;
    void showInserisciLayout() const;
    void showSearchLayout() const;
    void showListinoLayout() const;
    void aggiungiProdotto();
    void rimuoviProdotto();
    void cercaProdotto();
    void formModificaProdotto();
    void salvaModificaProdotto();
    void aggiornaTabellaProdotto();
    void salvaDati();
    void salvaComeDati();
    void caricaDati();

signals:
    void datiAggiornati();

};

#endif // CONTROLLER_H
