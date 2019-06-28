#include "listinolayout.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTableWidget>
#include <QHeaderView>

#include <QStringList>

#include <QPushButton>

#include "controller.h"
#include "../Modello/model.h"

listinoLayout::listinoLayout(QWidget* parent) :
    QWidget(parent),
    tabellaProdotti(new QTableWidget(this)) {

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* prodottiLayout = new QHBoxLayout();
    QVBoxLayout* prodottoLayout = new QVBoxLayout();

    prodottiLayout->setAlignment(Qt::AlignTop);

    tabellaProdotti->setColumnCount(7);
    tabellaProdotti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tabellaProdotti->setMaximumHeight(150);

    QStringList testoColonne("Tipo");
    testoColonne.append("Nome");
    testoColonne.append("Prezzo");
    testoColonne.append("Scadenza");
    testoColonne.append("Calorie");
    testoColonne.append("Eta Minima");
    testoColonne.append("Bar Code");

    tabellaProdotti->setHorizontalHeaderLabels(testoColonne);

    prodottiLayout->addWidget(tabellaProdotti);

    mainLayout->addLayout(prodottiLayout);
    mainLayout->addLayout(prodottoLayout);

}


void listinoLayout::aggiornaTabella(Model* modello) {
    tabellaProdotti->setRowCount(0);

    for(int i = 0; i < modello->count(); i++) {
        QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
        QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
        QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
        QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
        QTableWidgetItem* calorie = new QTableWidgetItem("36");
        QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
        QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

        tabellaProdotti->insertRow(i);
        tabellaProdotti->setItem(i, 0, tipo);
        tabellaProdotti->setItem(i, 1, nome);
        tabellaProdotti->setItem(i, 2, prezzo);
        tabellaProdotti->setItem(i, 3, scadenza);
        tabellaProdotti->setItem(i, 4, calorie);
        tabellaProdotti->setItem(i, 5, etaMinima);
        tabellaProdotti->setItem(i, 6, barCode);
    }
}
