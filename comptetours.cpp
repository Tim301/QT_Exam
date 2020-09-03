#include "comptetours.h"
#include <QPainter>
#include <iostream>

CompteTours::CompteTours(): Angle(130), AngleInit(130),AngleMax(280)
{
    setMinimumSize(300,300);

}

void CompteTours::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::black);
    //painter.
    //std::cout << width()/2 << ";" <<height()/2 << std::endl;
    int r1w = width()*0.9;
    int r1h = r1w;
    int r2w = width()*0.85;
    int r2h = r2w;
    int r1x = r1w/2;
    int r1y = r1x;
    int r2x = r2w/2;
    int r2y = r2x;
    QRegion r1(width()/2 - r1x, height()/2 - r1y ,r1w,r1h,QRegion::Ellipse);
    QRegion r2(width()/2 - r2x, height()/2 - r2y ,r2w,r2h,QRegion::Ellipse);
    QRegion r3(width()/2 - width()*0.5/2, height()/2 - height()*0.5/2 ,width()*0.5,height()*0.5,QRegion::Ellipse);
    int AiguilleH = width()/2*0.02;
    int AiguilleW = width()/2*0.8;
    //int AiguilleX = AiguilleW/2;
    int AiguilleY = AiguilleH/2;
    QRect Aiguille = QRect(width()/2 ,height()/2 - AiguilleY, AiguilleW, AiguilleH);

    QRegion marque(width()/2 - width()*0.5/2, height()/2 - height()*0.5/2 ,width()*0.5,height()*0.5,QRegion::Ellipse);
    QTransform tMarque = QTransform().translate( width()/2, height()/2 ).rotate(90).translate( -width()/2, -height()/2 );
    QPolygon rotatedMarque =  tMarque.mapToPolygon( Aiguille );
    painter.drawPolygon(rotatedMarque);

    //painter.fillRect(Aiguille,QBrush(Qt::black));

    std::cout << "RPM inside paintevent:  " <<  this->Angle << std::endl;
    QTransform t = QTransform().translate( width()/2, height()/2 ).rotate(this->Angle).translate( -width()/2, -height()/2 );
    QPolygon rotatedRect =  t.mapToPolygon( Aiguille );

    painter.drawPolygon(rotatedRect);
    painter.setClipRegion(r1 - r2);
    painter.fillRect(r1.boundingRect(),QBrush(Qt::black));
    painter.fillRect(r3.boundingRect(),QBrush(Qt::black));



    painter.setViewport( 0,0,1000,1000);
    painter.setWindow(500,500,1000,1000);

}

void CompteTours::SetRPM(int value){
    int tmp = ((float)( value*AngleMax/5000)) + AngleInit;
    std::cout << "tmp " << tmp << std::endl;
    this->Angle = tmp;
    std::cout << "Verif RPM: " << this->Angle << std::endl;
    update();
}
