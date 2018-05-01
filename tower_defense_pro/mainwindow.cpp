#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::easy_game()
{
    G = new Game(1);
    G->show();
    this->hide();
}

void MainWindow::medium_game()
{
    G = new Game(2);
    G->show();
    this->hide();
}

void MainWindow::hard_game()
{
    G = new Game(3);
    G->show();
    this->hide();
}


void MainWindow::on_pushButton_clicked()
{
    this->easy_game();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->medium_game();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->hard_game();
}
