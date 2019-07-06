#include "indexlayout.h"
#include "controller.h"

#include <QGridLayout>
#include <QVBoxLayout>

#include <QPixmap>
#include <QLabel>
#include <QPushButton>

indexLayout::indexLayout(QWidget *parent) :
    QWidget(parent),
    titoloLabel(new QLabel(this)),
    imageLabel(new QLabel(this)),
    titolo(QPixmap(":/Graphic/qbar-title.png")),
    image(QPixmap(":/Graphic/logo.png")),
    inserisciBottone(new QPushButton("Inserisci", this)),
    ricercaBottone(new QPushButton("Ricerca", this)),
    listinoBottone(new QPushButton("Listino", this)) {

    QGridLayout* mainLayout = new QGridLayout(this);
    QVBoxLayout* buttonLayout = new QVBoxLayout();

    // TITOLO
    titoloLabel->setFixedSize(390, 80);
    titolo = titolo.scaled(titoloLabel->size(),Qt::KeepAspectRatio);
    titoloLabel->setPixmap(titolo);
    titoloLabel->setAlignment(Qt::AlignCenter);

    // LOGO
    imageLabel->setFixedSize(300, 300);
    image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
    imageLabel->setPixmap(image);

    // BUTTON LAYOUT
    buttonLayout->addWidget(inserisciBottone);
    buttonLayout->addWidget(ricercaBottone);
    buttonLayout->addWidget(listinoBottone);
    buttonLayout->setAlignment(inserisciBottone, Qt::AlignCenter);
    buttonLayout->setAlignment(ricercaBottone, Qt::AlignCenter);
    buttonLayout->setAlignment(listinoBottone, Qt::AlignCenter);

    // MAIN LAYOUT
    mainLayout->addWidget(titoloLabel, 0, 2, 1, 2);
    mainLayout->addWidget(imageLabel, 0, 0, 5, 2);
    mainLayout->addLayout(buttonLayout, 1, 2, 3, 4);

    // CONNECT
    connect(inserisciBottone, SIGNAL(clicked(bool)), parent, SLOT(showInserisciLayout()));
    connect(ricercaBottone, SIGNAL(clicked(bool)), parent, SLOT(showSearchLayout()));
    connect(listinoBottone, SIGNAL(clicked(bool)), parent, SLOT(showListinoLayout()));
}
