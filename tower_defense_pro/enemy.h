#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem* parent = 0);
    void setSpeed(double s);
    bool got_hit;
public slots:
    void move_forward();
    void check_if_hit();
private:
    double speed = 0.8;
    QGraphicsPolygonItem* hit_area;
};

#endif // ENEMY_H
