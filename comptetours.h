#ifndef COMPTETOURS_H
#define COMPTETOURS_H
#include <QWidget>

class CompteTours: public QWidget
{
public:
    CompteTours();
private:
    void paintEvent(QPaintEvent *event);
};

#endif // COMPTETOURS_H
