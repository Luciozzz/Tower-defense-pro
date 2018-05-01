#include <QPixmap>
#include <QTimer>
#include <QtMath>

#include "enemy.h"
#include "bullet.h"

Enemy::Enemy(QGraphicsItem *parent)
{
    //set the icon:
    setPixmap(QPixmap(":/images/enemy1.png"));

    //set the hit range (point set):
    QVector<QPointF> points;
    points << QPointF(1,0) << QPointF(3,0) << QPointF(4,1.732)
           << QPointF(3,3.464) << QPointF(1,3.464) << QPointF(0,1.732);
    const int SCALE = 9;
    for(size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE;
    }

    //set the hit range (polygon):
    QPolygonF polygon(points);
    hit_area = new QGraphicsPolygonItem(polygon, this);

    QPointF polygon_center(2.2,2.2);
    polygon_center *= SCALE;
    polygon_center = mapToScene(polygon_center);
    QPointF enemy_center(x()+36, y()+38);
    QLineF line(polygon_center, enemy_center);
    hit_area->setPos(x()+line.dx(), y()+line.dy());

    //enemy behaviors:
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move_forward()));
    connect(timer, SIGNAL(timeout()), this, SLOT(check_if_hit()));
    timer->start(20);
}

void Enemy::setSpeed(double s)
{
    speed = s;
}

void Enemy::move_forward()
{
    //enemy will move downwards with different preset speeds:
    double angle = rotation();
    double dx = speed * qSin(qDegreesToRadians(angle));
    double dy = speed * qCos(qDegreesToRadians(angle));
    setPos(x()+dx, y()+dy);
}

void Enemy::check_if_hit()
{
    //check if the enemy is being hit by a bullet:
    QList<QGraphicsItem*> colliding_items = hit_area->collidingItems();
    if(colliding_items.size() == 1){
        got_hit = false;
        return;
    }
    for(size_t i = 0, n = colliding_items.size(); i < n; i++){
        Bullet* bullet = dynamic_cast<Bullet*>(colliding_items[i]);
        if(bullet){
            got_hit = true;
            delete bullet;
            delete this;
        }
    }
}
