#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVector>
#include <QPushButton>

#include "Tower.h"
#include "Enemy.h"

class Game: public QGraphicsView{
public:
    Game(int);

    void mousePressEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *key);

    QGraphicsScene* scene;
    Tower* t;
    QPoint* center;
    QVector<Enemy*> enemy_list;
    const QVector<int> spawn_pos = {0,80,160,240,320,400,480,560,640,720};
    QVector<double> speed_list;

    QPushButton* get_win() const;
    QPushButton* get_lose() const;

private:
    QPushButton* win;
    QPushButton* lose;

};

#endif // GAME_H
