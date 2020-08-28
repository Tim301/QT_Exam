#include "mainwindow.h"
#include "comptetours.h"
#include <QSlider>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CompteTours *vroum;
    QSlider *Vitesse;
    Vitesse->setMinimum(0);
    Vitesse->setMaximum(5000); // 5000 rpm car c'est une essence
    Vitesse->setValue(800); // 800 est le régine moteur
    Vitesse->setOrientation(Qt::Vertical);
    QHBoxLayout* PasWidget;
    //PasWidget->addWidget(vroum);
    PasWidget->addWidget(Vitesse);

    QWidget* Widget_Final = new QWidget(this);
    Widget_Final->setLayout(PasWidget);
    setCentralWidget(Widget_Final);
    setMinimumSize(sizeHint());

}

void MainWindow::SetRPM(int RPM){

}

MainWindow::~MainWindow()
{

}

