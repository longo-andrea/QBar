#include "controller.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QCloseEvent>

#include <QLayout>

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>

#include "../Modello/Gerarchia/analcolico.h"
#include "../Modello/Gerarchia/cocktail.h"
#include "../Modello/Gerarchia/vino.h"
#include "../Modello/Gerarchia/brioche.h"
#include "../Modello/Gerarchia/panino.h"
#include "../Modello/Gerarchia/piadina.h"

#include "insertformexception.h"

Controller::Controller(QWidget *parent) :
    QWidget(),
    fileData(QString("Data.json")),
    modello(new Model()),
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
    QAction* salvaFile = new QAction("Salva", fileMenu);
    QAction* salvaComeFile = new QAction("Salva come", fileMenu);
    QAction* caricaFile = new QAction("Carica", fileMenu);

    fileMenu->addAction(salvaFile);
    fileMenu->addAction(salvaComeFile);
    fileMenu->addAction(caricaFile);
    menuBar->addMenu(fileMenu);
    menuBar->addAction(indexMenu);
    menuBar->addAction(inserisciMenu);
    menuBar->addAction(ricercaMenu);
    menuBar->addAction(listinoMenu);

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

    // MODEL CONNECT
    connect(insertL->getAggiungiBottone(), SIGNAL(clicked()), this, SLOT(aggiungiProdotto()));
    connect(searchL->getCercaBottone(), SIGNAL(clicked()), this, SLOT(cercaProdotto()));
    connect(searchL->getRimuoviBottone(), SIGNAL(clicked()), this, SLOT(rimuoviProdotto()));
    connect(searchL->getModificaBottone(), SIGNAL(clicked()), this, SLOT(formModificaProdotto()));
    connect(searchL->getSalvaModificaBottone(), SIGNAL(clicked()), this, SLOT(salvaModificaProdotto()));
    connect(listinoL->getModificaBottone(), SIGNAL(clicked()), this, SLOT(formModificaProdotto()));
    connect(listinoL->getSalvaModificaBottone(), SIGNAL(clicked()), this, SLOT(salvaModificaProdotto()));
    connect(listinoL->getRimuoviBottone(), SIGNAL(clicked()), this, SLOT(rimuoviProdotto()));
    connect(this, SIGNAL(datiAggiornati()), this, SLOT(aggiornaTabellaProdotto()));
    connect(salvaFile, SIGNAL(triggered()), this, SLOT(salvaDati()));
    connect(salvaComeFile, SIGNAL(triggered()), this, SLOT(salvaComeDati()));
    connect(caricaFile, SIGNAL(triggered()), this, SLOT(caricaDati()));
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
    try {
        std::string tipo = insertL->getTipo();

        if(insertL->getNome() == "" || insertL->getCarboidrati() < 0 || insertL->getProteine() < 0 || insertL->getGrassi() < 0 || insertL->getBarCode() == "" || insertL->getScadenza() == 0 || insertL->getEtaMinima() == 0)
            throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");

        if(tipo == "Analcolico"){
            if(insertL->getPrezzoNetto() == 0 || insertL->getLitri() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Analcolico(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Analcolico::stringToVariante(insertL->getVariante()), Analcolico::stringToContenitore(insertL->getContenitore()), insertL->getLitri(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
        } else if (tipo == "Cocktail") {
            if(insertL->getPrezzoNetto() == 0 || insertL->getGradazione() ==0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Cocktail(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Cocktail::stringToQuantita(insertL->getQuantita()), Cocktail::stringToClassificazione(insertL->getFamiglia()), insertL->getGradazione(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
        } else if (tipo == "Vino") {
            if(insertL->getPrezzoNetto() == 0 || insertL->getGradazione() ==0 || insertL->getLitri() ==0 || insertL->getAnno() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Vino(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoNetto(), insertL->getBarCode(), Vino::stringToRegione(insertL->getRegione()), insertL->getGradazione(), insertL->getLitri(), insertL->getAnno(), insertL->getIsAlcoholic(), insertL->getScadenza(), insertL->getEtaMinima()));
        } else if (tipo == "Brioche") {
            if(insertL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Brioche(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Brioche::stringToImpasto(insertL->getImpasto()), Brioche::stringToForma(insertL->getForma()), Brioche::stringToRipieno(insertL->getRipieno()), insertL->getScadenza(), insertL->getEtaMinima()));
        } else if (tipo == "Panino") {
            if(insertL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Panino(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Panino::stringToPane(insertL->getPane()), insertL->getScadenza(), insertL->getEtaMinima()));
        } else if (tipo == "Piadina") {
            if(insertL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            modello->add(new Piadina(insertL->getNome(), insertL->getCarboidrati(), insertL->getProteine(), insertL->getGrassi(), insertL->getPrezzoPreparazione(), insertL->getIsVegan(), insertL->getBarCode(), Piadina::stringToImpasto(insertL->getImpastoPiadina()), insertL->getScadenza(), insertL->getEtaMinima()));
        }

        insertL->clearDataForm();
        emit datiAggiornati();

    } catch(insertFormException ife) {
        QMessageBox::warning(this, "Attenzione", ife.getWarning());
    }
}

void Controller::rimuoviProdotto() {
    if(sender() == listinoL->getRimuoviBottone() && listinoL->getIndiceProdottoSelezionato() != -1)
        modello->remove(listinoL->getIndiceProdottoSelezionato());
    else if(sender() == searchL->getRimuoviBottone() && searchL->getIndiceProdottoSelezionato() != -1)
        modello->remove(searchL->getIndiceProdottoSelezionato());

    emit datiAggiornati();
}

void Controller::cercaProdotto() {
    searchL->aggiornaTabella(modello);
}

void Controller::formModificaProdotto() {
    if(sender() == listinoL->getModificaBottone() && listinoL->getIndiceProdottoSelezionato() != -1)
        listinoL->formModificaProdotto(modello);
    else if(sender() == searchL->getModificaBottone() && searchL->getIndiceProdottoSelezionato() != -1)
        searchL->formModificaProdotto(modello);
}

void Controller::salvaModificaProdotto() {
    if(sender() == listinoL->getSalvaModificaBottone())
        listinoL->salvaModificaProdotto(modello);
    else if(sender() == searchL->getSalvaModificaBottone())
        searchL->salvaModificaProdotto(modello);
    emit datiAggiornati();
}

void Controller::aggiornaTabellaProdotto() {
    listinoL->aggiornaTabella(modello);
    searchL->aggiornaTabella(modello);
}

void Controller::salvaDati() {
    modello->save(fileData.toStdString());
}

void Controller::salvaComeDati() {
    fileData = QFileDialog::getSaveFileName(this, "Salva come", "", "JSON (*.json);;All Files (*)");

    modello->save(fileData.toStdString());
}

void Controller::caricaDati() {
    fileData = QFileDialog::getOpenFileName(this, "Carica", "", "JSON (*.json);;All Files (*)");

    modello->load(fileData.toStdString());

    emit datiAggiornati();
}

void Controller::closeEvent (QCloseEvent *event) {
    QMessageBox::StandardButton esciBottone = QMessageBox::question( this, "QBar", "Vuoi salvare gli eventuali dati non salvati prima di uscire?", QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if (esciBottone == QMessageBox::Yes) {
        modello->save(fileData.toStdString());
        event->accept();
    } else if(esciBottone == QMessageBox::No) {
        event->accept();
    }
    else{
        event->ignore();
    }
}
