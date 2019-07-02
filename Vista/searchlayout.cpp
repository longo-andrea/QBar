#include "searchlayout.h"

#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QIntValidator>

searchLayout::searchLayout(QWidget* parent) :
    QWidget(parent),
    cercaParametro(new QComboBox(this)),
    cercaValore(new QLineEdit(this)),
    ricercaBottone(new QPushButton("Ricerca")),
    rimuoviBottone(new QPushButton("Elimina")),
    modificaBottone(new QPushButton("Modifica")) {

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    searchBarLayout = new QHBoxLayout();
    viewTableLayout = new QVBoxLayout();

    // SEARCH BAR
    cercaParametro->addItem("Nome");
    cercaParametro->addItem("Tipo");
    cercaParametro->addItem("Scadenza");
    cercaParametro->addItem("Eta Minima");

    searchBarLayout->setAlignment(Qt::AlignTop);
    searchBarLayout->addWidget(cercaParametro);
    searchBarLayout->addWidget(cercaValore);
    searchBarLayout->addWidget(ricercaBottone);

    // TABELLA PRODOTTI
    tabellaProdotti = new QTableWidget(0, 7, this);

    QStringList testoColonne("Tipo");
    testoColonne.append("Nome");
    testoColonne.append("Prezzo");
    testoColonne.append("Scadenza");
    testoColonne.append("Calorie");
    testoColonne.append("Eta Minima");
    testoColonne.append("Bar Code");

    tabellaProdotti->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tabellaProdotti->setMaximumHeight(150);
    tabellaProdotti->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabellaProdotti->setHorizontalHeaderLabels(testoColonne);
    tabellaProdotti->setSelectionBehavior(QAbstractItemView::SelectRows);

    viewTableLayout->setAlignment(Qt::AlignTop);
    viewTableLayout->addWidget(tabellaProdotti);
    viewTableLayout->addWidget(rimuoviBottone);
    viewTableLayout->addWidget(modificaBottone);

    // MAIN LAYOUT
    mainLayout->addLayout(searchBarLayout);
    mainLayout->addLayout(viewTableLayout);

    // CONNECT
    connect(cercaParametro, SIGNAL(activated(int)), this, SLOT(setLineEdit(int)));
}

QPushButton* searchLayout::getCercaBottone() const {
    return ricercaBottone;
}

QPushButton* searchLayout::getRimuoviBottone() const {
    return rimuoviBottone;
}

QString searchLayout::getCercaValore() const {
    return cercaValore->text();
}

int searchLayout::getIndiceProdottoSelezionato() const {
    return indiciRicerca[tabellaProdotti->currentRow()];
}

void searchLayout::aggiornaTabella(Model* modello) {
    tabellaProdotti->setRowCount(0);
    indiciRicerca.clear();

    if(cercaParametro->currentIndex() == 0) {
        int i,j;
        for(i = 0, j = 0; modello->getIndexNome(getCercaValore().toStdString(), i) != -1; i++, j++){

            i = modello->getIndexNome(getCercaValore().toStdString(), i);

            QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
            QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
            QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
            QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
            QTableWidgetItem* calorie = new QTableWidgetItem(QString(QString::number((*modello)[i]->calcolaCalorie())));
            QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
            QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

            tabellaProdotti->insertRow(j);
            tabellaProdotti->setItem(j, 0, tipo);
            tabellaProdotti->setItem(j, 1, nome);
            tabellaProdotti->setItem(j, 2, prezzo);
            tabellaProdotti->setItem(j, 3, scadenza);
            tabellaProdotti->setItem(j, 4, calorie);
            tabellaProdotti->setItem(j, 5, etaMinima);
            tabellaProdotti->setItem(j, 6, barCode);

            indiciRicerca.append(i);
        }
    }
    else if(cercaParametro->currentIndex() == 1) {
        int i,j;
        for(i = 0, j = 0; modello->getIndexTipo(getCercaValore().toStdString(), i) != -1; i++, j++){

            i = modello->getIndexTipo(getCercaValore().toStdString(), i);

            QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
            QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
            QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
            QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
            QTableWidgetItem* calorie = new QTableWidgetItem(QString(QString::number((*modello)[i]->calcolaCalorie())));
            QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
            QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

            tabellaProdotti->insertRow(j);
            tabellaProdotti->setItem(j, 0, tipo);
            tabellaProdotti->setItem(j, 1, nome);
            tabellaProdotti->setItem(j, 2, prezzo);
            tabellaProdotti->setItem(j, 3, scadenza);
            tabellaProdotti->setItem(j, 4, calorie);
            tabellaProdotti->setItem(j, 5, etaMinima);
            tabellaProdotti->setItem(j, 6, barCode);

            indiciRicerca.append(i);
        }
    }
    else if(cercaParametro->currentIndex() == 2) {
        int i,j;
        for(i = 0, j = 0; modello->getIndexScadenza(getCercaValore().toInt(), i) != -1; i++, j++){

            i = modello->getIndexScadenza(getCercaValore().toInt(), i);

            QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
            QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
            QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
            QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
            QTableWidgetItem* calorie = new QTableWidgetItem(QString(QString::number((*modello)[i]->calcolaCalorie())));
            QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
            QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

            tabellaProdotti->insertRow(j);
            tabellaProdotti->setItem(j, 0, tipo);
            tabellaProdotti->setItem(j, 1, nome);
            tabellaProdotti->setItem(j, 2, prezzo);
            tabellaProdotti->setItem(j, 3, scadenza);
            tabellaProdotti->setItem(j, 4, calorie);
            tabellaProdotti->setItem(j, 5, etaMinima);
            tabellaProdotti->setItem(j, 6, barCode);

            indiciRicerca.append(i);
        }
    }
    else if(cercaParametro->currentIndex() == 3) {
        int i,j;
        for(i = 0, j = 0; modello->getIndexEtaMinima(getCercaValore().toInt(), i) != -1; i++, j++){

            i = modello->getIndexEtaMinima(getCercaValore().toInt(), i);

            QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
            QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
            QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
            QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
            QTableWidgetItem* calorie = new QTableWidgetItem(QString(QString::number((*modello)[i]->calcolaCalorie())));
            QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
            QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

            tabellaProdotti->insertRow(j);
            tabellaProdotti->setItem(j, 0, tipo);
            tabellaProdotti->setItem(j, 1, nome);
            tabellaProdotti->setItem(j, 2, prezzo);
            tabellaProdotti->setItem(j, 3, scadenza);
            tabellaProdotti->setItem(j, 4, calorie);
            tabellaProdotti->setItem(j, 5, etaMinima);
            tabellaProdotti->setItem(j, 6, barCode);

            indiciRicerca.append(i);
        }
    }

}

void searchLayout::pulisciTabella() {
    tabellaProdotti->removeRow(tabellaProdotti->currentRow());
}

void searchLayout::setLineEdit(int parametro) {
    cercaValore->clear();

    if(parametro == 0 || parametro == 1)
        cercaValore->setValidator(new QRegExpValidator());
    else if(parametro == 2)
        cercaValore->setValidator(new QIntValidator(2019, 2100, this));
    else if(parametro == 3)
        cercaValore->setValidator(new QIntValidator(14, 100, this));
}
