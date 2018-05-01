#include <QPixmap>
#include <QTimer>
#include <QtMath>

#include "Bullet.h"
#include "Enemy.h"

Bullet::Bullet(QGraphicsItem *parent){
    setPixmap(QPixmap(":/images/bullet.png"));

    //bullet movement:
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(20);
}

void Bullet::move(){
    const int STEP_SIZE = 10;
    double angle = rotation();
    double dx = STEP_SIZE * qSin(qDegreesToRadians(angle));
    double dy = STEP_SIZE * qCos(qDegreesToRadians(angle));

    setPos(x()+dx, y()+dy);
}
