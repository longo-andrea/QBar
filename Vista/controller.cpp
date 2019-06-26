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

#include "../Modello/Gerarchia/analcolico.h"

Controller::Controller(Model* model, QWidget *parent) :
    QWidget(parent),
    modello(model),
    mainLayout(new QVBoxLayout(this)),
    menuBar(new QMenuBar()),
    searchL(new searchLayout(this)),
    indexL(new indexLayout(this)),
    insertL(new insertLayout(this)) {

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
    QAction* esciMenu = new QAction("Esci", menuBar);
    QAction* salvaFile = new QAction("Salva", fileMenu);
    QAction* caricaFile = new QAction("Carica", fileMenu);

    fileMenu->addAction(salvaFile);
    fileMenu->addAction(caricaFile);
    menuBar->addMenu(fileMenu);
    menuBar->addAction(indexMenu);
    menuBar->addAction(inserisciMenu);
    menuBar->addAction(ricercaMenu);
    menuBar->addAction(esciMenu);

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(indexL);
    mainLayout->addWidget(insertL);
    mainLayout->addWidget(searchL);

    showIndexLayout();

    setLayout(mainLayout);

    // MENU BAR CONNECT
    connect(indexMenu, SIGNAL(triggered()), this, SLOT(showIndexLayout()));
    connect(inserisciMenu, SIGNAL(triggered()), this, SLOT(showInserisciLayout()));
    connect(ricercaMenu, SIGNAL(triggered()), this, SLOT(showSearchLayout()));
    connect(esciMenu, SIGNAL(triggered()), QApplication::instance(), SLOT(quit()));


    connect(insertL->getAggiungiBottone(), SIGNAL(clicked()), this, SLOT(aggiungiProdotto()));

}

Controller::~Controller() {}

void Controller::showIndexLayout() const {
    mainLayout->setAlignment(Qt::AlignCenter);

    insertL->hide();
    searchL->hide();
    indexL->show();
}

void Controller::showInserisciLayout() const {
    mainLayout->setAlignment(Qt::AlignTop);

    indexL->hide();
    searchL->hide();
    insertL->show();
}


void Controller::showSearchLayout() const {
    mainLayout->setAlignment(Qt::AlignTop);

    indexL->hide();
    insertL->hide();
    searchL->show();
}

void Controller::aggiungiProdotto() {

    std::string nome = insertL->getNome().toStdString();

    Prodotto* test = new Analcolico(nome);
    modello->add(test);

    modello->save("data.json");

}
