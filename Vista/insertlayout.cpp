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
    tipoLabel(new QLabel("Tipo")),
    nomeLabel(new QLabel("Nome")),
    scadenzaLabel(new QLabel("Scadenza")),
    etaMinimaLabel(new QLabel("Eta Minima")),
    barCodeLabel(new QLabel("Bar Code")),
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
    tipoValore(new QComboBox(this)),
    nomeValore(new QLineEdit(this)),
    scadenzaValore(new QLineEdit(this)),
    etaMinimaValore(new QLineEdit(this)),
    barCodeValore(new QLineEdit(this)),
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
    aggiungiBottone(new QPushButton("Aggiungi", this)),
    clearDataBottone(new QPushButton(QIcon(":/Graphic/clear.png"), "", this)) {

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    formGroupBox = new QGroupBox("Riempire il form per inserire un nuovo prodotto.");
    formLayout = new QFormLayout();
    buttonLayout = new QHBoxLayout();
    imageLayout = new QHBoxLayout();

    // setting items
    scadenzaValore->setValidator(new QIntValidator(2019, 2100, this));
    etaMinimaValore->setValidator(new QIntValidator(14, 100, this));

    tipoValore->addItem("Analcolico");
    tipoValore->addItem("Cocktail");
    tipoValore->addItem("Vino");
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
    formLayout->addRow(tipoLabel, tipoValore);
    formLayout->addRow(nomeLabel, nomeValore);
    formLayout->addRow(scadenzaLabel, scadenzaValore);
    formLayout->addRow(etaMinimaLabel, etaMinimaValore);
    formLayout->addRow(carboidratiLabel, carboidratiValore);
    formLayout->addRow(proteineLabel, proteineValore);
    formLayout->addRow(grassiLabel, grassiValore);
    formLayout->addRow(barCodeLabel, barCodeValore);

    // Form initialization
    formGroupBox->setLayout(formLayout);
    impostaForm(0);

    // Button Layout
    buttonLayout->addWidget(clearDataBottone);
    buttonLayout->addWidget(aggiungiBottone);

    mainLayout->addWidget(formGroupBox);
    mainLayout->addLayout(imageLayout);

    // CONNECT
    connect(tipoValore, SIGNAL(activated(int)), this, SLOT(impostaForm(int)));
    connect(clearDataBottone, SIGNAL(clicked()), this, SLOT(clearDataForm()));
}

std::string insertLayout::getNome() const {
    return nomeValore->text().toStdString();
}

int insertLayout::getScadenza() const {
    return scadenzaValore->text().toInt();
}

int insertLayout::getEtaMinima() const {
    return etaMinimaValore->text().toInt();
}


std::string insertLayout:: getBarCode() const {
    return barCodeValore->text().toStdString();
}

std::string insertLayout::getTipo() const {
    return tipoValore->currentText().toStdString();
}

double insertLayout::getCarboidrati() const {
    return carboidratiValore->text().toDouble();
}

double insertLayout::getProteine() const {
    return proteineValore->text().toDouble();
}

double insertLayout::getGrassi() const {
    return grassiValore->text().toDouble();
}

bool insertLayout::getIsAlcoholic() const {
    return isAlcoholicValore->isChecked();
}

double insertLayout::getPrezzoNetto() const {
    return prezzoNettoValore->text().toDouble();
}

bool insertLayout::getIsVegan() const {
    return isVeganValore->isChecked();
}

double insertLayout::getPrezzoPreparazione() const {
    return prezzoPreparazioneValore->text().toDouble();
}

std::string insertLayout::getVariante() const {
    return varianteValore->currentText().toStdString();
}

std::string insertLayout::getContenitore() const {
    return contenitoreValore->currentText().toStdString();
}

double insertLayout::getLitri() const {
    return litriValore->text().toDouble();
}

std::string insertLayout::getRegione() const {
    return regioneValore->currentText().toStdString();
}

int insertLayout::getAnno() const {
    return annoValore->text().toInt();
}

double insertLayout::getGradazione() const {
    return gradazioneValore->text().toDouble();
}

std::string insertLayout::getQuantita() const {
    return quantitaValore->currentText().toStdString();
}

std::string insertLayout::getFamiglia() const {
    return famigliaValore->currentText().toStdString();
}

std::string insertLayout::getImpasto() const {
    return impastoValore->currentText().toStdString();
}

std::string insertLayout::getForma() const {
    return formaValore->currentText().toStdString();
}

std::string insertLayout::getRipieno() const {
    return ripienoValore->currentText().toStdString();
}

std::string insertLayout::getPane() const {
    return paneValore->currentText().toStdString();
}

std::string insertLayout::getImpastoPiadina() const {
    return impastoPiadinaValore->currentText().toStdString();
}

void insertLayout::setNome(QString text) {
    nomeValore->setText(text);
}

void insertLayout::setScadenza(QString);
void insertLayout::setEtaMinima(QString);
void insertLayout::setBarCode(QString);
void insertLayout::setTipo(QString);
void insertLayout::setCarboidrati(QString);
void insertLayout::setProteine(QString);
void insertLayout::setGrassi(QString);
void insertLayout::setIsAlcoholic(QString);
void insertLayout::setPrezzoNetto(QString);
void insertLayout::setIsVegan(QString);
void insertLayout::setPrezzoPreparazione(QString);
void insertLayout::setVariante(QString);
void insertLayout::setContenitore(QString);
void insertLayout::setLitri(QString);
void insertLayout::setRegione(QString);
void insertLayout::setAnno(QString);
void insertLayout::setGradazione(QString);
void insertLayout::setQuantita(QString);
void insertLayout::setFamiglia(QString);
void insertLayout::setImpasto(QString);
void insertLayout::setForma(QString);
void insertLayout::setRipieno(QString);
void insertLayout::setPane(QString);
void insertLayout::setImpastoPiadina(QString);

void insertLayout::disableTipoValore() {
    tipoValore->setEnabled(false);
}

QPushButton* insertLayout::getAggiungiBottone() const {
    return aggiungiBottone;
}

void insertLayout::clearDataForm() const {
    nomeValore->clear();
    scadenzaValore->clear();
    etaMinimaValore->clear();
    barCodeValore->clear();
    carboidratiValore->clear();
    proteineValore->clear();
    grassiValore->clear();
    isAlcoholicValore->setChecked(false);
    prezzoNettoValore->clear();
    isVeganValore->setChecked(false);
    prezzoPreparazioneValore->clear();
    litriValore->clear();
    annoValore->clear();
    gradazioneValore->clear();
}

void insertLayout::clearForm() const {

    formLayout->removeWidget(prezzoNettoLabel);
    formLayout->removeWidget(prezzoNettoValore);
    formLayout->removeWidget(isAlcoholicLabel);
    formLayout->removeWidget(isAlcoholicValore);
    formLayout->removeWidget(isVeganLabel);
    formLayout->removeWidget(isVeganValore);
    formLayout->removeWidget(prezzoPreparazioneLabel);
    formLayout->removeWidget(prezzoPreparazioneValore);
    formLayout->removeWidget(varianteLabel);
    formLayout->removeWidget(varianteValore);
    formLayout->removeWidget(contenitoreLabel);
    formLayout->removeWidget(contenitoreValore);
    formLayout->removeWidget(quantitaLabel);
    formLayout->removeWidget(quantitaValore);
    formLayout->removeWidget(famigliaLabel);
    formLayout->removeWidget(famigliaValore);
    formLayout->removeWidget(regioneLabel);
    formLayout->removeWidget(regioneValore);
    formLayout->removeWidget(annoLabel);
    formLayout->removeWidget(annoValore);
    formLayout->removeWidget(litriLabel);
    formLayout->removeWidget(litriValore);
    formLayout->removeWidget(gradazioneLabel);
    formLayout->removeWidget(gradazioneValore);
    formLayout->removeWidget(impastoLabel);
    formLayout->removeWidget(impastoValore);
    formLayout->removeWidget(formaLabel);
    formLayout->removeWidget(formaValore);
    formLayout->removeWidget(ripienoLabel);
    formLayout->removeWidget(ripienoValore);
    formLayout->removeWidget(paneLabel);
    formLayout->removeWidget(paneValore);
    formLayout->removeWidget(impastoPiadinaValore);
    formLayout->removeItem(buttonLayout);

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
            formLayout->addRow(buttonLayout);

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
            formLayout->addRow(buttonLayout);

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
            formLayout->addRow(buttonLayout);

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
        case 3: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(impastoLabel, impastoValore);
            formLayout->addRow(formaLabel, formaValore);
            formLayout->addRow(ripienoLabel, ripienoValore);
            formLayout->addRow(buttonLayout);

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
        case 4: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(paneLabel, paneValore);
            formLayout->addRow(buttonLayout);

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
        case 5: {
            clearForm();

            formLayout->addRow(isVeganLabel, isVeganValore);
            formLayout->addRow(prezzoPreparazioneLabel, prezzoPreparazioneValore);
            formLayout->addRow(impastoLabel, impastoPiadinaValore);
            formLayout->addRow(buttonLayout);

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
