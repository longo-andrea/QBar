#ifndef CONTROLLER_H
#define CONTROLLERH

#include <QMainWindow>
#include <QWidget>
#include <QLayout>

#include "Modello/model.h"

#include <QMenuBar>
#include "searchlayout.h"
#include "indexlayout.h"
#include "insertlayout.h"
#include "listinolayout.h"

class Controller : public QWidget
{
    Q_OBJECT
private:
    Model* modello;

    QVBoxLayout* mainLayout;
    QMenuBar* menuBar;
    searchLayout* searchL;
    indexLayout* indexL;
    insertLayout* insertL;
    listinoLayout* listinoL;

public:
    explicit Controller(Model*, QWidget * =0);
    ~Controller() override;

public slots:
    void showIndexLayout() const;
    void showInserisciLayout() const;
    void showSearchLayout() const;
    void showListinoLayout() const;

    void aggiungiProdotto();

};

#endif // CONTROLLER_H
