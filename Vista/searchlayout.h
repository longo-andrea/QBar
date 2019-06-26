#ifndef SEARCHLAYOUT_H
#define SEARCHLAYOUT_H

#include <QWidget>
#include <QLayout>

#include <QLabel>
#include <QComboBox>
#include <QLineEdit>


class searchLayout : public QWidget {
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* tipoLabel;
    QLabel* scadenzaLabel;

    QLineEdit* cercaNome;
    QComboBox* cercaTipo;
    QLineEdit* cercaScadenza;

public:
    explicit searchLayout(QWidget* =nullptr);

};

#endif // SEARCHLAYOUT_H
