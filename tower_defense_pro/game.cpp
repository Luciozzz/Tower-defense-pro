#include <QGraphicsScene>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QtMath>
#include <QVector>
#include <QPushButton>
#include <algorithm>
#include <QTime>
#include <QCoreApplication>

#include "Game.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"

Game::Game(int level)
{
    //create the game scene:
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,800);
    setScene(scene);

    //create a tower:
    t = new Tower();
    center = new QPoint(365, 600);
    t->setPos(center->x(), center->y());
    scene->addItem(t);

    setFixedSize(800, 800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //difficulty chooser:
    if(level == 1){
        speed_list << 1.8 << 0.8 << 1.1 << 1.5 << 1.4 << 1.2 << 0.7 << 0.6 << 1 << 1.7;
    }else if(level == 2){
        speed_list << 2.1 << 1 << 1.6 << 1.9 << 1.2 << 2.2 << 1.5 << 1.8 << 1.1 << 1.5;
    }else if(level == 3){
        speed_list << 2.6 << 2.4 << 2.3 << 2.1 << 2 << 2.5 << 1.7 << 2.6 << 1.9 << 2.8;
    }

    //create an enemy list:
    Enemy* e1 = new Enemy();
    Enemy* e2 = new Enemy();
    Enemy* e3 = new Enemy();
    Enemy* e4 = new Enemy();
    Enemy* e5 = new Enemy();
    Enemy* e6 = new Enemy();
    Enemy* e7 = new Enemy();
    Enemy* e8 = new Enemy();
    Enemy* e9 = new Enemy();
    Enemy* e10 = new Enemy();

    enemy_list << e1 << e2 << e3 << e4 << e5 << e6 << e7 << e8 << e9 << e10;
    for(int i = 0, n = enemy_list.size(); i < n; i++){
        enemy_list[i]->setPos(spawn_pos[i],0);
        enemy_list[i]->setSpeed(speed_list[i]);
        scene->addItem(enemy_list[i]);
    }
}

void Game::mousePressEvent(QMouseEvent *event)
{
    //create the bullet
    Bullet* bullet = new Bullet();

    //set start position to be at the center of tower:
    bullet->setPos(center->x()+35, center->y()+31);

    //set the angle according to the mouse click:
    QLineF line(QPointF(t->x()+35, t->y()+31),QPointF(event->x(), event->y()));
    int theta = line.angle()+90;

    bullet->setRotation(theta);
    scene->addItem(bullet);
}

void Game::keyPressEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_W){
        center->setY(center->y()-20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_A){
        center->setX(center->x()-20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_S){
        center->setY(center->y()+20);
        t->setPos(center->x(), center->y());
    }else if(key->key() == Qt::Key_D){
        center->setX(center->x()+20);
        t->setPos(center->x(), center->y());
    }
}

QPushButton *Game::get_win() const
{
    return win;
}

QPushButton *Game::get_lose() const
{
    return lose;
}

