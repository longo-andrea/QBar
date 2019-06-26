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

    QLabel* imageLabel;
    QPushButton* aggiungiBottone;

public:
    explicit insertLayout(QWidget * =nullptr);

    QString getNome() const;
    QString getScadenza() const;
    QString getEtaMinima() const;

    QPushButton* getAggiungiBottone() const;

public slots:
    void clearForm() const;
    void impostaForm(int);

};

#endif // INSERTLAYOUT_H
