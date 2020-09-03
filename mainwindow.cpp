#include "mainwindow.h"
#include "comptetours.h"
#include "iostream"
#include <QSlider>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CompteTours *vroum = new CompteTours();
    QSlider *Vitesse = new QSlider();
    Vitesse->setMinimum(0);
    Vitesse->setMaximum(5000); // 5000 rpm car c'est une essence
    Vitesse->setValue(0); // 800 est le régine moteur
    Vitesse->setOrientation(Qt::Vertical);
    QHBoxLayout* PasWidget = new QHBoxLayout();
    PasWidget->addWidget(vroum);
    PasWidget->addWidget(Vitesse);

    QWidget* Widget_Final = new QWidget(this);
    Widget_Final->setLayout(PasWidget);
    setCentralWidget(Widget_Final);
    setMinimumSize(sizeHint());

    connect(Vitesse,SIGNAL(valueChanged(int)),vroum,SLOT(SetRPM(int)));

}

void MainWindow::SetRPM(int RPM){
    std::cout << RPM << std::endl;
    vroum->SetRPM(RPM);
}

MainWindow::~MainWindow()
{

}

