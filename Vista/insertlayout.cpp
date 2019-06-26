#include "insertlayout.h"

// Layout include
#include <QFormLayout>
#include <QHBoxLayout>

// Control include
#include <QIntValidator>
#include <QDoubleValidator>

// widget include
#include <QPixmap>
#include <QLabel>


insertLayout::insertLayout(QWidget *parent) :
    QWidget(parent),
    nomeLabel(new QLabel("Nome")),
    scadenzaLabel(new QLabel("Scadenza")),
    etaMinimaLabel(new QLabel("Eta Minima")),
    barCodeLabel(new QLabel("Bar Code")),
    tipoLabel(new QLabel("Tipo")),
    carboidratiLabel(new QLabel("Carboidrati")),
    proteineLabel(new QLabel("Proteine")),
    grassiLabel(new QLabel("Grassi")),
    isAlcoholicLabel(new QLabel("Alcolico")),
    prezzoNettoLabel(new QLabel("Prezzo")),
    isVeganLabel(new QLabel("Vegano")),
    prezzoPreparazioneLabel(new QLabel("Prezzo")),
    varianteLabel(new QLabel("Variante")),
    contenitoreLabel(new QLabel("Contenitore")),
    litriLabel(new QLabel("Litri")),
    regioneLabel(new QLabel("Regione")),
    annoLabel(new QLabel("Anno")),
    gradazioneLabel(new QLabel("Gradazione")),
    quantitaLabel(new QLabel("Quantita")),
    famigliaLabel(new QLabel("Famiglia")),
    impastoLabel(new QLabel("Impasto")),
    formaLabel(new QLabel("Forma")),
    ripienoLabel(new QLabel("Ripieno")),
    paneLabel(new QLabel("Pane")),
    nomeValore(new QLineEdit(this)),
    scadenzaValore(new QLineEdit(this)),
    etaMinimaValore(new QLineEdit(this)),
    barCodeValore(new QLineEdit(this)),
    tipoValore(new QComboBox(this)),
    carboidratiValore(new QLineEdit(this)),
    proteineValore(new QLineEdit(this)),
    grassiValore(new QLineEdit(this)),
    isAlcoholicValore(new QCheckBox(this)),
    prezzoNettoValore(new QLineEdit(this)),
    isVeganValore(new QCheckBox(this)),
    prezzoPreparazioneValore(new QLineEdit(this)),
    varianteValore(new QComboBox(this)),
    contenitoreValore(new QComboBox(this)),
    litriValore(new QLineEdit(this)),
    regioneValore(new QComboBox(this)),
    annoValore(new QLineEdit(this)),
    gradazioneValore(new QLineEdit(this)),
    quantitaValore(new QComboBox(this)),
    famigliaValore(new QComboBox(this)),
    impastoValore(new QComboBox(this)),
    formaValore(new QComboBox(this)),
    ripienoValore(new QComboBox(this)),
    paneValore(new QComboBox(this)),
    impastoPiadinaValore(new QComboBox(this)),
    imageLabel(new QLabel(this)),
    aggiungiBottone(new QPushButton("Aggiungi", this)) {

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    formGroupBox = new QGroupBox("Riempire il form per inserire un nuovo prodotto.");
    formLayout = new QFormLayout();
    //QHBoxLayout* buttonLayout = new QHBoxLayout();
    imageLayout = new QHBoxLayout();

    // setting items
    scadenzaValore->setValidator(new QIntValidator(2019, 2100, this));
    etaMinimaValore->setValidator(new QIntValidator(14, 100, this));

    tipoValore->addItem("Analcolico");
    tipoValore->addItem("Cocktail");
    tipoValore->addItem("Vino");
    tipoValore->insertSeparator(5);
    tipoValore->addItem("Brioche");
    tipoValore->addItem("Panino");
    tipoValore->addItem("Piadina");

    carboidratiValore->setValidator(new QIntValidator(0, 300, this));
    proteineValore->setValidator(new QIntValidator(0, 300, this));
    grassiValore->setValidator(new QIntValidator(0, 300, this));

    prezzoNettoValore->setValidator(new QDoubleValidator(0, 300, 2, this));
    prezzoPreparazioneValore->setValidator(new QDoubleValidator(0, 300, 2, this));

    varianteValore->addItem("Classica");
    varianteValore->addItem("Zero");
    varianteValore->addItem("Light");
    varianteValore->addItem("Diet");

    contenitoreValore->addItem("Lattina");
    contenitoreValore->addItem("Bottiglia");
    contenitoreValore->addItem("Spina");

    litriValore->setValidator(new QDoubleValidator(0, 300, 2, this));

    quantitaValore->addItem("Short");
    quantitaValore->addItem("Medium");
    quantitaValore->addItem("Long");

    famigliaValore->addItem("Coffe");
    famigliaValore->addItem("Cooler");
    famigliaValore->addItem("Exotic");
    famigliaValore->addItem("Wine");

    regioneValore->addItem("Emilia");
    regioneValore->addItem("Veneto");
    regioneValore->addItem("Friuli");
    regioneValore->addItem("Toscana");

    annoValore->setValidator(new QIntValidator(1000, 2100, this));

    gradazioneValore->setValidator(new QIntValidator(1000, 2100, this));

    impastoValore->addItem("Classico");
    impastoValore->addItem("Integrale");
    impastoValore->addItem("SenzaGlutine");

    formaValore->addItem("Cornetto");
    formaValore->addItem("Girella");
    formaValore->addItem("Ciambella");

    ripienoValore->addItem("Vuota");
    ripienoValore->addItem("Cioccolato");
    ripienoValore->addItem("Marmellata");
    ripienoValore->addItem("Crema");

    paneValore->addItem("Tartaruga");
    paneValore->addItem("Arabo");
    paneValore->addItem("Baguette");
    paneValore->addItem("Integrale");

    impastoPiadinaValore->addItem("Classico");
    impastoPiadinaValore->addItem("Cereali");
    impastoPiadinaValore->addItem("Integrale");
    impastoPiadinaValore->addItem("Kamut");

    // Adding basic item to the form
    formLayout->addRow(nomeLabel, nomeValore);
    formLayout->addRow(scadenzaLabel, scadenzaValore);
    formLayout->addRow(etaMinimaLabel, etaMinimaValore);
    formLayout->addRow(tipoLabel, tipoValore);
    formLayout->addRow(carboidratiLabel, carboidratiValore);
    formLayout->addRow(proteineLabel, proteineValore);
    formLayout->addRow(grassiLabel, grassiValore);
    formLayout->addRow(barCodeLabel, barCodeValore);

    // Form initialization
    formGroupBox->setLayout(formLayout);
    impostaForm(0);

    mainLayout->addWidget(formGroupBox);
    mainLayout->addLayout(imageLayout);

    connect(tipoValore, SIGNAL(activated(int)), this, SLOT(impostaForm(int)));
}

QString insertLayout::getNome() const {
    return nomeValore->text();
}

QString insertLayout::getScadenza() const {
    return scadenzaValore->text();
}

QString insertLayout::getEtaMinima() const {
    return etaMinimaValore->text();
}


QString insertLayout:: getBarCode() const {
    return barCodeValore->text();
}

QString insertLayout::getTipo() const {
    return tipoValore->currentText();
}

QString insertLayout::getCarboidrati() const {
    return carboidratiValore->text();
}

QString insertLayout::getProteine() const {
    return proteineValore->text();
}

QString insertLayout::getGrassi() const {
    return grassiValore->text();
}

bool insertLayout::getIsAlcoholic() const {
    return isAlcoholicValore->isChecked();
}

QString insertLayout::getPrezzoNetto() const {
    return prezzoNettoValore->text();
}

bool insertLayout::getIsVegan() const {
    return isVeganValore->isChecked();
}

QString insertLayout::getPrezzoPreparazione() const {
    return prezzoPreparazioneValore->text();
}

QString insertLayout::getVariante() const {
    return varianteValore->currentText();
}

QString insertLayout::getContenitore() const {
    return contenitoreValore->currentText();
}

QString insertLayout::getLitri() const {
    return litriValore->text();
}

QString insertLayout::getRegione() const {
    return regioneValore->currentText();
}

QString insertLayout::getAnno() const {
    return annoValore->text();
}

QString insertLayout::getGradazione() const {
    return gradazioneValore->text();
}

QString insertLayout::getQuantita() const {
    return quantitaValore->currentText();
}

QString insertLayout::getFamiglia() const {
    return famigliaValore->currentText();
}

QString insertLayout::getImpasto() const {
    return impastoValore->currentText();
}

QString insertLayout::getForma() const {
    return formaValore->currentText();
}

QString insertLayout::getRipieno() const {
    return ripienoValore->currentText();
}

QString insertLayout::getPane() const {
    return paneValore->currentText();
}

QString insertLayout::getImpastoPiadina() const {
    return impastoPiadinaValore->currentText();
}

QPushButton* insertLayout::getAggiungiBottone() const {
    return aggiungiBottone;
}

void insertLayout::clearForm() const {
    for(int i = 8; i < formLayout->rowCount(); i++)
        formLayout->takeRow(i);

    prezzoNettoLabel->setVisible(false);
    prezzoNettoValore->setVisible(false);
    isAlcoholicLabel->setVisible(false);
    isAlcoholicValore->setVisible(false);
    isVeganLabel->setVisible(false);
    isVeganValore->setVisible(false);
    prezzoPreparazioneLabel->setVisible(false);
    prezzoPreparazioneValore->setVisible(false);
    varianteLabel->setVisible(false);
    varianteValore->setVisible(false);
    contenitoreLabel->setVisible(false);
    contenitoreValore->setVisible(false);
    quantitaLabel->setVisible(false);
    quantitaValore->setVisible(false);
    famigliaLabel->setVisible(false);
    famigliaValore->setVisible(false);
    regioneLabel->setVisible(false);
    regioneValore->setVisible(false);
    annoLabel->setVisible(false);
    annoValore->setVisible(false);
    litriLabel->setVisible(false);
    litriValore->setVisible(false);
    gradazioneLabel->setVisible(false);
    gradazioneValore->setVisible(false);
    impastoLabel->setVisible(false);
    impastoValore->setVisible(false);
    formaLabel->setVisible(false);
    formaValore->setVisible(false);
    ripienoLabel->setVisible(false);
    ripienoValore->setVisible(false);
    paneLabel->setVisible(false);
    paneValore->setVisible(false);
    impastoPiadinaValore->setVisible(false);
}

void insertLayout::impostaForm(int tipo) {
    switch (tipo) {
        case 0: {
            clearForm();

            formLayout->addRow(prezzoNettoLabel, prezzoNettoValore);
            formLayout->addRow(contenitoreLabel, contenitoreValore);
            formLayout->addRow(varianteLabel, varianteValore);
            formLayout->addRow(litriLabel, litriValore);
            formLayout->addRow(aggiungiBottone);

            prezzoNettoLabel->setVisible(true);
            prezzoNettoValore->setVisible(true);
            varianteLabel->setVisible(true);
            varianteValore->setVisible(true);
            contenitoreLabel->setVisible(true);
            contenitoreValore->setVisible(true);
            litriLabel->setVisible(true);
            litriValore->setVisible(true);

            QPixmap image = QPixmap(":/Graphic/analcolico.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);
        }
        break;
        case 1: {
            clearForm();

            formLayout->addRow(isAlcoholicLabel, isAlcoholicValore);
            formLayout->addRow(prezzoNettoLabel, prezzoNettoValore);
            formLayout->addRow(quantitaLabel, quantitaValore);
            formLayout->addRow(famigliaLabel, famigliaValore);
            formLayout->addRow(gradazioneLabel, gradazioneValore);
            formLayout->addRow(aggiungiBottone);

            isAlcoholicLabel->setVisible(true);
            isAlcoholicValore->setVisible(true);
            prezzoNettoLabel->setVisible(true);
            prezzoNettoValore->setVisible(true);
            quantitaLabel->setVisible(true);
            quantitaValore->setVisible(true);
            famigliaLabel->setVisible(true);
            famigliaValore->setVisible(true);
            gradazioneLabel->setVisible(true);
            gradazioneValore->setVisible(true);

            isAlcoholicValore->setChecked(true);

            QPixmap image = QPixmap(":/Graphic/cocktail.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);
        }
        break;
        case 2: {
            clearForm();

            formLayout->addRow(isAlcoholicLabel, isAlcoholicValore);
            formLayout->addRow(prezzoNettoLabel, prezzoNettoValore);
            formLayout->addRow(regioneLabel, regioneValore);
            formLayout->addRow(annoLabel, annoValore);
            formLayout->addRow(litriLabel, litriValore);
            formLayout->addRow(gradazioneLabel, gradazioneValore);
            formLayout->addRow(aggiungiBottone);

            isAlcoholicLabel->setVisible(true);
            isAlcoholicValore->setVisible(true);
            prezzoNettoLabel->setVisible(true);
            prezzoNettoValore->setVisible(true);
            regioneLabel->setVisible(true);
            regioneValore->setVisible(true);
            annoLabel->setVisible(true);
            annoValore->setVisible(true);
            litriLabel->setVisible(true);
            litriValore->setVisible(true);
            gradazioneLabel->setVisible(true);
            gradazioneValore->setVisible(true);

            isAlcoholicValore->setChecked(true);

            QPixmap image = QPixmap(":/Graphic/vino.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);

        }
        break;
        case 4: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(impastoLabel, impastoValore);
            formLayout->addRow(formaLabel, formaValore);
            formLayout->addRow(ripienoLabel, ripienoValore);
            formLayout->addRow(aggiungiBottone);

            isVeganLabel->setVisible(true);
            isVeganValore->setVisible(true);
            prezzoPreparazioneLabel->setVisible(true);
            prezzoPreparazioneValore->setVisible(true);
            impastoLabel->setVisible(true);
            impastoValore->setVisible(true);
            formaLabel->setVisible(true);
            formaValore->setVisible(true);
            ripienoLabel->setVisible(true);
            ripienoValore->setVisible(true);

            isVeganValore->setChecked(false);

            QPixmap image = QPixmap(":/Graphic/brioche.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);
        }
        break;
        case 5: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(paneLabel, paneValore);
            formLayout->addRow(aggiungiBottone);

            isVeganLabel->setVisible(true);
            isVeganValore->setVisible(true);
            prezzoPreparazioneLabel->setVisible(true);
            prezzoPreparazioneValore->setVisible(true);
            paneLabel->setVisible(true);
            paneValore->setVisible(true);

            isVeganValore->setChecked(false);

            QPixmap image = QPixmap(":/Graphic/panino.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);
        }
        break;
        case 6: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(impastoLabel, impastoPiadinaValore);
            formLayout->addRow(aggiungiBottone);

            isVeganLabel->setVisible(true);
            isVeganValore->setVisible(true);
            prezzoPreparazioneLabel->setVisible(true);
            prezzoPreparazioneValore->setVisible(true);
            impastoLabel->setVisible(true);
            impastoPiadinaValore->setVisible(true);

            isVeganValore->setChecked(false);

            QPixmap image = QPixmap(":/Graphic/piadina.png");
            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);
            imageLayout->addWidget(imageLabel);
        }
        break;
    }
}

