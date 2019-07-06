#include "searchlayout.h"

#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>
#include <QIntValidator>
#include <QMessageBox>

#include "insertformexception.h"

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
    editL = new insertLayout();

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
    tabellaProdotti->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabellaProdotti->setHorizontalHeaderLabels(testoColonne);
    tabellaProdotti->verticalHeader()->setVisible(false);
    tabellaProdotti->setSelectionBehavior(QAbstractItemView::SelectRows);
    tabellaProdotti->setSelectionMode(QAbstractItemView::SingleSelection);

    viewTableLayout->setAlignment(Qt::AlignTop);
    viewTableLayout->addWidget(tabellaProdotti);
    viewTableLayout->addWidget(rimuoviBottone);
    viewTableLayout->addWidget(modificaBottone);

    // LAYOUT MODIFICA
    editL->getAggiungiBottone()->setText("Salva Modifiche");
    editL->disableTipoValore();
    editL->hide();

    // MAIN LAYOUT
    mainLayout->addLayout(searchBarLayout);
    mainLayout->addLayout(viewTableLayout);

    // CONNECT
    connect(cercaParametro, SIGNAL(activated(int)), this, SLOT(setLineEdit(int)));
    connect(modificaBottone, SIGNAL(clicked()), this, SLOT(showModifica()));
    connect(getSalvaModificaBottone(), SIGNAL(clicked()), editL, SLOT(hide()));
}

QPushButton* searchLayout::getCercaBottone() const {
    return ricercaBottone;
}

QPushButton* searchLayout::getRimuoviBottone() const {
    return rimuoviBottone;
}

QPushButton* searchLayout::getModificaBottone() const {
    return modificaBottone;
}

QPushButton* searchLayout::getSalvaModificaBottone() const {
    return editL->getAggiungiBottone();
}

QString searchLayout::getCercaValore() const {
    return cercaValore->text();
}

int searchLayout::getIndiceProdottoSelezionato() const {
    if(tabellaProdotti->currentRow() != -1)
        return indiciRicerca[tabellaProdotti->currentRow()];
    else
        return -1;
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

void searchLayout::formModificaProdotto(Model* modello) {
    editL->setTipo(QString::fromStdString((*modello)[getIndiceProdottoSelezionato()]->getTipo()));
    editL->setNome(QString::fromStdString((*modello)[getIndiceProdottoSelezionato()]->getNome()));
    editL->setScadenza(QString::number((*modello)[getIndiceProdottoSelezionato()]->getScadenza()));
    editL->setEtaMinima(QString::number((*modello)[getIndiceProdottoSelezionato()]->getEtaMinima()));
    editL->setBarCode(QString::fromStdString((*modello)[getIndiceProdottoSelezionato()]->getBarCode()));

    if(editL->getTipo() == "Analcolico"){
        editL->setCarboidrati(QString::number(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setPrezzoNetto(QString::number(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoNetto()));
        editL->setContenitore(QString::fromStdString(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->contenitoreToString()));
        editL->setVariante(QString::fromStdString(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->varianteToString()));
        editL->setLitri(QString::number(static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->getLitri()));
    }
    else if(editL->getTipo() == "Cocktail"){
        editL->setCarboidrati(QString::number(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setIsAlcoholic(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->isAlcoholic());
        editL->setPrezzoNetto(QString::number(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoNetto()));
        editL->setQuantita(QString::fromStdString(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->quantitaToString()));
        editL->setFamiglia(QString::fromStdString(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->famigliaToString()));
        editL->setGradazione(QString::number(static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->getGradazioneAlcolica()));
    }
    else if(editL->getTipo() == "Vino"){
        editL->setCarboidrati(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setIsAlcoholic(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->isAlcoholic());
        editL->setPrezzoNetto(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoNetto()));
        editL->setRegione(QString::fromStdString(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->regioneToString()));
        editL->setAnno(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getAnnoProduzione()));
        editL->setLitri(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getLitri()));
        editL->setGradazione(QString::number(static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->getGradazioneAlcolica()));
    }
    else if(editL->getTipo() == "Brioche"){
        editL->setCarboidrati(QString::number(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setIsVegan(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->isVegan());
        editL->setPrezzoPreparazione(QString::number(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoPreparazione()));
        editL->setImpasto(QString::fromStdString(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->impastoToString()));
        editL->setForma(QString::fromStdString(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->formaToString()));
        editL->setRipieno(QString::fromStdString(static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->ripienoToString()));
    }
    else if(editL->getTipo() == "Panino"){
        editL->setCarboidrati(QString::number(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setIsVegan(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->isVegan());
        editL->setPrezzoPreparazione(QString::number(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoPreparazione()));
        editL->setPane(QString::fromStdString(static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->paneToString()));
    }
    else if(editL->getTipo() == "Piadina"){
        editL->setCarboidrati(QString::number(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->getCarboidrati()));
        editL->setProteine(QString::number(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->getProteine()));
        editL->setGrassi(QString::number(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->getGrassi()));
        editL->setIsVegan(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->isVegan());
        editL->setPrezzoPreparazione(QString::number(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->getPrezzoPreparazione()));
        editL->setImpastoPiadina(QString::fromStdString(static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->impastoToString()));
    }
}

void searchLayout::salvaModificaProdotto(Model* modello) {
    try {
        std::string tipo = editL->getTipo();

        if(editL->getNome() == "" || editL->getCarboidrati() == 0 || editL->getProteine() == 0 || editL->getGrassi() == 0 || editL->getBarCode() == "" || editL->getScadenza() == 0 || editL->getEtaMinima() == 0)
            throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");

        if(tipo == "Analcolico"){
            if(editL->getPrezzoNetto() == 0 || editL->getLitri() ==0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoNetto(editL->getPrezzoNetto());
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setContenitore(Analcolico::stringToContenitore(editL->getContenitore()));
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setVariante(Analcolico::stringToVariante(editL->getVariante()));
            static_cast<Analcolico*>((*modello)[getIndiceProdottoSelezionato()])->setLitri(editL->getLitri());

        } else if (tipo == "Cocktail") {
            if(editL->getPrezzoNetto() == 0 || editL->getGradazione() ==0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoNetto(editL->getPrezzoNetto());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setAlcoholic(editL->getIsAlcoholic());
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setQuantita(Cocktail::stringToQuantita(editL->getQuantita()));
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setAlcoholic(Cocktail::stringToClassificazione(editL->getFamiglia()));
            static_cast<Cocktail*>((*modello)[getIndiceProdottoSelezionato()])->setGradazioneAlcolica(editL->getGradazione());
        } else if (tipo == "Vino") {
            if(editL->getPrezzoNetto() == 0 || editL->getGradazione() ==0 || editL->getLitri() ==0 || editL->getAnno() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoNetto(editL->getPrezzoNetto());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setAlcoholic(editL->getIsAlcoholic());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setRegione(Vino::stringToRegione(editL->getRegione()));
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setAnnoProduzione(editL->getAnno());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setLitri(editL->getLitri());
            static_cast<Vino*>((*modello)[getIndiceProdottoSelezionato()])->setGradazioneAlcolica(editL->getGradazione());
        } else if (tipo == "Brioche") {
            if(editL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoPreparazione(editL->getPrezzoPreparazione());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setIsVegan(editL->getIsVegan());
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setImpasto(Brioche::stringToImpasto(editL->getImpasto()));
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setForma(Brioche::stringToForma(editL->getForma()));
            static_cast<Brioche*>((*modello)[getIndiceProdottoSelezionato()])->setRipieno(Brioche::stringToRipieno(editL->getRipieno()));
        } else if (tipo == "Panino") {
            if(editL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoPreparazione(editL->getPrezzoPreparazione());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setIsVegan(editL->getIsVegan());
            static_cast<Panino*>((*modello)[getIndiceProdottoSelezionato()])->setPane(Panino::stringToPane(editL->getPane()));
        } else if (tipo == "Piadina") {
            if(editL->getPrezzoPreparazione() == 0) throw insertFormException("Verifica di aver compilato tutti i campi, oppure che non ci siano valori nulli.");
            (*modello)[getIndiceProdottoSelezionato()]->setNome(editL->getNome());
            (*modello)[getIndiceProdottoSelezionato()]->setScadenza(editL->getScadenza());
            (*modello)[getIndiceProdottoSelezionato()]->setEtaMinima(editL->getEtaMinima());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setCarboidrati(editL->getCarboidrati());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setProteine(editL->getProteine());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setGrassi(editL->getGrassi());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setBarCode(editL->getBarCode());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setPrezzoPreparazione(editL->getPrezzoPreparazione());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setIsVegan(editL->getIsVegan());
            static_cast<Piadina*>((*modello)[getIndiceProdottoSelezionato()])->setImpasto(Piadina::stringToImpasto(editL->getImpastoPiadina()));
        }

    } catch(insertFormException ife) {
        QMessageBox::warning(this, "Attenzione", ife.getWarning());
    }
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

void searchLayout::showModifica() const {
    if(getIndiceProdottoSelezionato() != -1)
        editL->show();
}
