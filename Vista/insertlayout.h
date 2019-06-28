#ifndef INSERTLAYOUT_H
#define INSERTLAYOUT_H

#include <QWidget>

#include <QFormLayout>
#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QString>

class insertLayout : public QWidget {
    Q_OBJECT
private:
    QGroupBox* formGroupBox;
    QFormLayout* formLayout;
    QHBoxLayout* imageLayout;

    QLabel* nomeLabel;
    QLabel* scadenzaLabel;
    QLabel* etaMinimaLabel;
    QLabel* barCodeLabel;
    QLabel* tipoLabel;
    QLabel* carboidratiLabel;
    QLabel* proteineLabel;
    QLabel* grassiLabel;
    QLabel* isAlcoholicLabel;
    QLabel* prezzoNettoLabel;
    QLabel* isVeganLabel;
    QLabel* prezzoPreparazioneLabel;
    QLabel* varianteLabel;
    QLabel* contenitoreLabel;
    QLabel* litriLabel;
    QLabel* regioneLabel;
    QLabel* annoLabel;
    QLabel* gradazioneLabel;
    QLabel* quantitaLabel;
    QLabel* famigliaLabel;
    QLabel* impastoLabel;
    QLabel* formaLabel;
    QLabel* ripienoLabel;
    QLabel* paneLabel;

    QLineEdit* nomeValore;
    QLineEdit* scadenzaValore;
    QLineEdit* etaMinimaValore;
    QLineEdit* barCodeValore;
    QComboBox* tipoValore;
    QLineEdit* carboidratiValore;
    QLineEdit* proteineValore;
    QLineEdit* grassiValore;
    QCheckBox* isAlcoholicValore;
    QLineEdit* prezzoNettoValore;
    QCheckBox* isVeganValore;
    QLineEdit* prezzoPreparazioneValore;
    QComboBox* varianteValore;
    QComboBox* contenitoreValore;
    QLineEdit* litriValore;
    QComboBox* regioneValore;
    QLineEdit* annoValore;
    QLineEdit* gradazioneValore;
    QComboBox* quantitaValore;
    QComboBox* famigliaValore;
    QComboBox* impastoValore;
    QComboBox* formaValore;
    QComboBox* ripienoValore;
    QComboBox* paneValore;
    QComboBox* impastoPiadinaValore;

    QLabel* imageLabel;
    QPushButton* aggiungiBottone;

public:
    explicit insertLayout(QWidget * =nullptr);

    std::string getNome() const;
    int getScadenza() const;
    int getEtaMinima() const;
    std::string getBarCode() const;
    std::string getTipo() const;
    double getCarboidrati() const;
    double getProteine() const;
    double getGrassi() const;
    bool getIsAlcoholic() const;
    double getPrezzoNetto() const;
    bool getIsVegan() const;
    double getPrezzoPreparazione() const;
    std::string getVariante() const;
    std::string getContenitore() const;
    double getLitri() const;
    std::string getRegione() const;
    int getAnno() const;
    double getGradazione() const;
    std::string getQuantita() const;
    std::string getFamiglia() const;
    std::string getImpasto() const;
    std::string getForma() const;
    std::string getRipieno() const;
    std::string getPane() const;
    std::string getImpastoPiadina() const;


    QPushButton* getAggiungiBottone() const;

public slots:
    void clearForm() const;
    void impostaForm(int);

};

#endif // INSERTLAYOUT_H
