#ifndef CONTROLLER_H
#define CONTROLLERH

#include <QMainWindow>
#include <QWidget>
#include <QLayout>

#include <QMenuBar>
#include "searchlayout.h"
#include "indexlayout.h"
#include "insertlayout.h"

class Controller : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QMenuBar* menuBar;
    searchLayout* searchL;
    indexLayout* indexL;
    insertLayout* insertL;


public:
    explicit Controller(QWidget * =0);
    ~Controller() override;

public slots:
    void showIndexLayout() const;
    void showInserisciLayout() const;
    void showSearchLayout() const;

};

#endif // CONTROLLER_H
