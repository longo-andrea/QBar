#include "indexlayout.h"
#include "controller.h"

#include <QGridLayout>
#include <QVBoxLayout>

#include <QPixmap>
#include <QLabel>
#include <QPushButton>

indexLayout::indexLayout(QWidget *parent) :
    QWidget(parent),
    imageLabel(new QLabel(this)),
    image(QPixmap(":/Graphic/logo.png")),
    inserisciBottone(new QPushButton("Inserisci", this)),
    ricercaBottone(new QPushButton("Ricerca", this)) {

    QGridLayout* mainLayout = new QGridLayout(this);
    QVBoxLayout* buttonLayout = new QVBoxLayout();

    imageLabel->setFixedSize(280, 280);
    image = image.scaled(imageLabel->size(),Qt::KeepAspectRatio);
    imageLabel->setPixmap(image);

    buttonLayout->addWidget(inserisciBottone);
    buttonLayout->addWidget(ricercaBottone);

    mainLayout->setHorizontalSpacing(150);
    mainLayout->addWidget(imageLabel, 0, 0, 4, 1);
    mainLayout->addLayout(buttonLayout, 1, 2, 2, 2);

    // QPUSHBUTTON CONNECT
    connect(inserisciBottone, SIGNAL(clicked(bool)), parent, SLOT(rimuoviTest()));
    connect(ricercaBottone, SIGNAL(clicked(bool)), parent, SLOT(showSearchLayout()));
}
