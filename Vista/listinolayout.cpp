#include "listinolayout.h"

 #include <QHBoxLayout>

#include <QPushButton>

listinoLayout::listinoLayout(QWidget* parent) :
    QWidget(parent) {

    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QPushButton* btn =  new QPushButton("Click");

    mainLayout->addWidget(btn);

}
