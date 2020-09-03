#ifndef COMPTETOURS_H
#define COMPTETOURS_H
#include <QWidget>

class CompteTours: public QWidget
{
Q_OBJECT
public:
    CompteTours();
    void paintEvent(QPaintEvent *event);
private:
    int Angle;
    const int  AngleInit;
    const int AngleMax;
public slots:
    void SetRPM(int value);
};

#endif // COMPTETOURS_H
