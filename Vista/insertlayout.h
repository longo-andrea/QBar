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

    QString getNome() const;
    QString getScadenza() const;
    QString getEtaMinima() const;
    QString getBarCode() const;
    QString getTipo() const;
    QString getCarboidrati() const;
    QString getProteine() const;
    QString getGrassi() const;
    bool getIsAlcoholic() const;
    QString getPrezzoNetto() const;
    bool getIsVegan() const;
    QString getPrezzoPreparazione() const;
    QString getVariante() const;
    QString getContenitore() const;
    QString getLitri() const;
    QString getRegione() const;
    QString getAnno() const;
    QString getGradazione() const;
    QString getQuantita() const;
    QString getFamiglia() const;
    QString getImpasto() const;
    QString getForma() const;
    QString getRipieno() const;
    QString getPane() const;
    QString getImpastoPiadina() const;


    QPushButton* getAggiungiBottone() const;

public slots:
    void clearForm() const;
    void impostaForm(int);

};

#endif // INSERTLAYOUT_H
