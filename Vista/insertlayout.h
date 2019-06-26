#ifndef INSERTLAYOUT_H
#define INSERTLAYOUT_H

#include <QWidget>
#include <QFormLayout>
#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>

class insertLayout : public QWidget {
    Q_OBJECT
private:
    QGroupBox* formGroupBox;
    QFormLayout* formLayout;
    QHBoxLayout* imageLayout;

    QLabel* nomeLabel;
    QLabel* scadenzaLabel;
    QLabel* etaMinimaLabel;
    QLabel* tipoLabel;
    QLabel* carboidratiLabel;
    QLabel* proteineLabel;
    QLabel* grassiLabel;
    QLabel* isAlcoholicLabel;
    QLabel* prezzoNettoLabel;
    QLabel* barCodeLabel;
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
    QComboBox* tipoValore;
    QLineEdit* carboidratiValore;
    QLineEdit* proteineValore;
    QLineEdit* grassiValore;
    QCheckBox* isAlcoholicValore;
    QLineEdit* prezzoNettoValore;
    QLineEdit* barCodeValore;
    QComboBox* varianteValore;
    QComboBox* contenitoreValore;
    QLineEdit* litriValore;
    QComboBox* regioneValore;
    QLineEdit* annoValore;
    QLineEdit* gradazioneValore;
    QComboBox* quantitaValore;
    QComboBox* famigliaValore;

    QLabel* imageLabel;

public:
    explicit insertLayout(QWidget * =nullptr);

public slots:
    void clearForm() const;
    void impostaForm(int);


};

#endif // INSERTLAYOUT_H
