#ifndef INDEXLAYOUT_H
#define INDEXLAYOUT_H

#include <QWidget>

#include <QPixmap>
#include <QLabel>
#include <QPushButton>

class indexLayout: public QWidget {
    Q_OBJECT
private:
    QLabel* titoloLabel;
    QLabel* imageLabel;

    QPixmap titolo;
    QPixmap image;

    QPushButton* inserisciBottone;
    QPushButton* ricercaBottone;
    QPushButton* listinoBottone;

public:
    explicit indexLayout(QWidget * =nullptr);
};

#endif // INDEXLAYOUT_H
