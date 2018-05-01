#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void easy_game();
    void medium_game();
    void hard_game();

private slots:
    void on_pushButton_clicked();//click these buttons to select difficulty when entering the game
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Game* G;
    QPushButton* ingameExit;
};

#endif // MAINWINDOW_H
