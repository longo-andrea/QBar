#include "listinolayout.h"
#include "insertformexception.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>

#include <QStringList>

#include <QPushButton>

#include "controller.h"
#include "../Modello/model.h"

listinoLayout::listinoLayout(QWidget* parent) :
    QWidget(parent),
    rimuoviBottone(new QPushButton("Elimina")),
    modificaBottone(new QPushButton("Modifica")) {

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    viewTableLayout = new QVBoxLayout();
    editL = new insertLayout();

    // TABELLA PRODOTTI
    tabellaProdotti = new QTableWidget(0, 6, this);

    QStringList testoColonne("Tipo");
    testoColonne.append("Nome");
    testoColonne.append("Prezzo");
    testoColonne.append("Scadenza");
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
    mainLayout->addLayout(viewTableLayout);

    // CONNECT
    connect(modificaBottone, SIGNAL(clicked()), this, SLOT(showModifica()));
    connect(getSalvaModificaBottone(), SIGNAL(clicked()), editL, SLOT(hide()));
}

QPushButton* listinoLayout::getRimuoviBottone() const {
    return rimuoviBottone;
}

QPushButton* listinoLayout::getModificaBottone() const {
    return modificaBottone;
}

QPushButton* listinoLayout::getSalvaModificaBottone() const {
    return editL->getAggiungiBottone();
}

int listinoLayout::getIndiceProdottoSelezionato() const {
    return tabellaProdotti->currentRow();
}

void listinoLayout::aggiornaTabella(Model* modello) {
    tabellaProdotti->setRowCount(0);

    for(int i = 0; i < modello->count(); i++) {
        QTableWidgetItem* tipo = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getTipo())));
        QTableWidgetItem* nome = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getNome())));
        QTableWidgetItem* prezzo = new QTableWidgetItem(QString(QString::number((*modello)[i]->getPrezzo())));
        QTableWidgetItem* scadenza = new QTableWidgetItem(QString(QString::number((*modello)[i]->getScadenza())));
        QTableWidgetItem* etaMinima = new QTableWidgetItem(QString(QString::number((*modello)[i]->getEtaMinima())));
        QTableWidgetItem* barCode = new QTableWidgetItem(QString(QString::fromStdString((*modello)[i]->getBarCode())));

        tabellaProdotti->insertRow(i);
        tabellaProdotti->setItem(i, 0, tipo);
        tabellaProdotti->setItem(i, 1, nome);
        tabellaProdotti->setItem(i, 2, prezzo);
        tabellaProdotti->setItem(i, 3, scadenza);
        tabellaProdotti->setItem(i, 4, etaMinima);
        tabellaProdotti->setItem(i, 5, barCode);
    }
}

void listinoLayout::formModificaProdotto(Model* modello) {
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

void listinoLayout::salvaModificaProdotto(Model* modello) {
    try {
        std::string tipo = editL->getTipo();

        if(editL->getNome() == "" || editL->getCarboidrati() < 0 || editL->getProteine() < 0 || editL->getGrassi() < 0 || editL->getBarCode() == "" || editL->getScadenza() == 0 || editL->getEtaMinima() == 0)
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

void listinoLayout::showModifica() const {
    if(getIndiceProdottoSelezionato() != -1)
        editL->show();
}
