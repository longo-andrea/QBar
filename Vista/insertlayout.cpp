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

//METHODS
QString insertLayout::getNome() const {
    return nomeValore->text();
}

QString insertLayout::getScadenza() const {
    return scadenzaValore->text();
}

QString insertLayout::getEtaMinima() const {
    return etaMinimaValore->text();
}

QPushButton* insertLayout::getAggiungiBottone() const {
    return aggiungiBottone;
}

// SLOTS
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

            isVeganLabel->setVisible(true);
            isVeganValore->setVisible(true);
            prezzoPreparazioneLabel->setVisible(true);
            prezzoPreparazioneValore->setVisible(true);

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

            QPixmap image = QPixmap(":/Graphic/panino.png");

            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);

            imageLayout->addWidget(imageLabel);
        }
        break;
        case 6: {
            clearForm();



            QPixmap image = QPixmap(":/Graphic/piadina.png");

            imageLabel->setFixedSize(280, 280);
            image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
            imageLabel->setPixmap(image);

            imageLayout->addWidget(imageLabel);
        }
        break;
    }
}

