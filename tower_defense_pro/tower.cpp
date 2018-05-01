#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>

#include "Tower.h"
#include "Enemy.h"

Tower::Tower(QGraphicsItem* parent){
    setPixmap(QPixmap(":/images/tower.png"));

    //set the hit range (point set):
    QVector<QPointF> points;
    points << QPointF(1,0) << QPointF(3,0) << QPointF(4,1.732)
           << QPointF(3,3.464) << QPointF(1,3.464) << QPointF(0,1.732);
    const int SCALE = 13;
    for(size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE;
    }

    //set the hit range (polygon):
    QPolygonF polygon(points);
    hit_area = new QGraphicsPolygonItem(polygon, this);

    QPointF polygon_center(2.2,2.2);
    polygon_center *= SCALE;
    polygon_center = mapToScene(polygon_center);
    QPointF tower_center(x()+38, y()+38);
    QLineF line(polygon_center, tower_center);
    hit_area->setPos(x()+line.dx(), y()+line.dy());

    //tower behavior:
    QTimer* check_timer = new QTimer(this);
    connect(check_timer, SIGNAL(timeout()), this, SLOT(check_if_hit()));
    check_timer->start(20);
}

void Tower::check_if_hit(){
    //check if the tower is hit by an enemy:
    QList<QGraphicsItem*> colliding_items = hit_area->collidingItems();

    if(colliding_items.size() == 1){
        got_hit = false;
        return;
    }
    for(size_t i = 0, n = colliding_items.size(); i < n; i++){
        Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
        if(enemy){
            got_hit = true;
            delete enemy;
        }
    }
}
