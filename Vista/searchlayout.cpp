#include "searchlayout.h"

#include <QFormLayout>

#include <QLabel>

searchLayout::searchLayout(QWidget* parent) :
    QWidget(parent),
    nomeLabel(new QLabel("Nome")),
    tipoLabel(new QLabel("Tipo")),
    scadenzaLabel(new QLabel("Scadenza")),
    cercaNome(new QLineEdit(this)),
    cercaTipo(new QComboBox(this)),
    cercaScadenza(new QLineEdit(this)) {

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout();

    cercaTipo->addItem("-- None --");
    cercaTipo->insertSeparator(5);
    cercaTipo->addItem("Analcolico");
    cercaTipo->addItem("Cocktail");
    cercaTipo->addItem("Vino");
    cercaTipo->insertSeparator(5);
    cercaTipo->addItem("Brioche");
    cercaTipo->addItem("Panino");
    cercaTipo->addItem("Piadina");

    nomeLabel->setFixedWidth(80);
    tipoLabel->setFixedWidth(80);

    formLayout->addRow(nomeLabel, cercaNome);
    formLayout->addRow(tipoLabel, cercaTipo);
    formLayout->addRow(scadenzaLabel, cercaScadenza);

    mainLayout->addLayout(formLayout);
}
