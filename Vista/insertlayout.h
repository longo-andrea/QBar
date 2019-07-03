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
    QHBoxLayout* buttonLayout;

    QLabel* tipoLabel;
    QLabel* nomeLabel;
    QLabel* scadenzaLabel;
    QLabel* etaMinimaLabel;
    QLabel* barCodeLabel;
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

    QComboBox* tipoValore;
    QLineEdit* nomeValore;
    QLineEdit* scadenzaValore;
    QLineEdit* etaMinimaValore;
    QLineEdit* barCodeValore;
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
    QPushButton* clearDataBottone;

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

    void setNome(QString);
    void setScadenza(QString);
    void setEtaMinima(QString);
    void setBarCode(QString);
    void setTipo(QString);
    void setCarboidrati(QString);
    void setProteine(QString);
    void setGrassi(QString);
    void setIsAlcoholic(QString);
    void setPrezzoNetto(QString);
    void setIsVegan(QString);
    void setPrezzoPreparazione(QString);
    void setVariante(QString);
    void setContenitore(QString);
    void setLitri(QString);
    void setRegione(QString);
    void setAnno(QString);
    void setGradazione(QString);
    void setQuantita(QString);
    void setFamiglia(QString);
    void setImpasto(QString);
    void setForma(QString);
    void setRipieno(QString);
    void setPane(QString);
    void setImpastoPiadina(QString);

    void disableTipoValore();
    QPushButton* getAggiungiBottone() const;

public slots:
    void clearDataForm() const;
    void clearForm() const;
    void impostaForm(int);

};

#endif // INSERTLAYOUT_H
