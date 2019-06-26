#ifndef INDEXLAYOUT_H
#define INDEXLAYOUT_H

#include <QWidget>

#include <QPixmap>
#include <QLabel>
#include <QPushButton>


class indexLayout: public QWidget {
    Q_OBJECT
private:
    QLabel* imageLabel;
    QPixmap image;
    QPushButton* inserisciBottone;
    QPushButton* ricercaBottone;

public:
    explicit indexLayout(QWidget * =nullptr);
};

#endif // INDEXLAYOUT_H
