#include "controller.h"

#include <QDesktopWidget>
#include <QApplication>

#include <QLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QPushButton>

#include <QPixmap>
#include <QLabel>

#include <QString>
#include <string>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "../Modello/Gerarchia/analcolico.h"
#include "../Modello/Gerarchia/cocktail.h"
#include "../Modello/Gerarchia/vino.h"
#include "../Modello/Gerarchia/brioche.h"
#include "../Modello/Gerarchia/panino.h"
#include "../Modello/Gerarchia/piadina.h"

Controller::Controller(Model* model, QWidget *parent) :
    QWidget(parent),
    modello(model),
    mainLayout(new QVBoxLayout(this)),
    menuBar(new QMenuBar()),
    searchL(new searchLayout(this)),
    indexL(new indexLayout(this)),
    insertL(new insertLayout(this)),
    listinoL(new listinoLayout(this)) {

    // MAIN WINDOW
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setWindowTitle("QBar");
    setWindowIcon(QIcon(":/Graphic/icon.png"));
    setFixedSize(QSize(780, 540));

    // MENU
    QMenu* fileMenu = new QMenu("File", menuBar);
    QAction* indexMenu = new QAction("Home", menuBar);
    QAction* inserisciMenu = new QAction("Inserisci", menuBar);
    QAction* ricercaMenu = new QAction("Ricerca", menuBar);
    QAction* listinoMenu = new QAction("Listino", menuBar);
    QAction* esciMenu = new QAction("Esci", menuBar);
    QAction* salvaFile = new QAction("Salva", fileMenu);
    QAction* caricaFile = new QAction("Carica", fileMenu);

    fileMenu->addAction(salvaFile);
    fileMenu->addAction(caricaFile);
    menuBar->addMenu(fileMenu);
    menuBar->addAction(indexMenu);
    menuBar->addAction(inserisciMenu);
    menuBar->addAction(ricercaMenu);
    menuBar->addAction(listinoMenu);
    menuBar->addAction(esciMenu);

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(indexL);
    mainLayout->addWidget(insertL);
    mainLayout->addWidget(searchL);
    mainLayout->addWidget(listinoL);

    showIndexLayout();

    setLayout(mainLayout);

    // MENU BAR CONNECT
    connect(indexMenu, SIGNAL(triggered()), this, SLOT(showIndexLayout()));
    connect(inserisciMenu, SIGNAL(triggered()), this, SLOT(showInserisciLayout()));
    connect(ricercaMenu, SIGNAL(triggered()), this, SLOT(showSearchLayout()));
    connect(listinoMenu, SIGNAL(triggered()), this, SLOT(showListinoLayout()));
    connect(esciMenu, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));

    // MODEL CONNECT
    connect(insertL->getAggiungiBottone(), SIGNAL(clicked()), this, SLOT(aggiungiProdotto()));
    connect(this, SIGNAL(datiAggiornati()), this, SLOT(aggiornaTabellaProdotto()));
    connect(salvaFile, SIGNAL(triggered()), this, SLOT(salvaDati()));
}

Controller::~Controller() {}

void Controller::showIndexLayout() const {
    mainLayout->setAlignment(Qt::AlignCenter);

    insertL->hide();
    searchL->hide();
    listinoL->hide();
    indexL->show();
}

void Controller::showInserisciLayout() const {
    mainLayout->setAlignment(Qt::AlignTop);

    indexL->hide();
    searchL->hide();
    listinoL->hide();
    insertL->show();
}


void Controller::showSearchLayout() const {
    mainLayout->setAlignment(Qt::AlignTop);

    indexL->hide();
    insertL->hide();
    listinoL->hide();
    searchL->show();
}

void Controller::showListinoLayout() const {
    mainLayout->setAlignment(Qt::AlignTop);

    indexL->hide();
    insertL->hide();
    searchL->hide();
    listinoL->show();
}

void Controller::aggiungiProdotto() {

    std::string tipo = insertL->getTipo();

    if(tipo == "Analcolico"){
        modello->add(new Analcolico(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Analcolico::stringToVariante(insertL->getVariante()), Analcolico::stringToContenitore(insertL->getContenitore()), insertL->getLitri(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
    } else if (tipo == "Cocktail") {
        modello->add(new Cocktail(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Cocktail::stringToQuantita(insertL->getQuantita()), Cocktail::stringToClassificazione(insertL->getFamiglia()), insertL->getGradazione(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
    } else if (tipo == "Vino") {
        modello->add(new Vino(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Vino::stringToRegione(insertL->getRegione()), insertL->getGradazione(), insertL->getLitri(), insertL->getAnno(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
    } else if (tipo == "Brioche") {
        modello->add(new Brioche(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Brioche::stringToImpasto(insertL->getImpasto()), Brioche::stringToForma(insertL->getForma()), Brioche::stringToRipieno(insertL->getRipieno()), insertL->getScadenza(), insertL->getEtaMinima()));
    } else if (tipo == "Panino") {
        modello->add(new Panino(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Panino::stringToPane(insertL->getPane()), insertL->getScadenza(), insertL->getEtaMinima()));
    } else if (tipo == "Piadina") {
        modello->add(new Piadina(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Piadina::stringToImpasto(insertL->getImpastoPiadina()), insertL->getScadenza(), insertL->getEtaMinima()));
    }


    emit datiAggiornati();
}

void Controller::aggiornaTabellaProdotto() {
    listinoL->aggiornaTabella(modello);
}

void Controller::salvaDati() const {
    modello->save("Data.json");
}
