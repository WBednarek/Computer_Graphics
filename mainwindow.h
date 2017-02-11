#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainview.h"
#include "setline.h"
#include "turnshader.h"
#include <chrono>
#include <random>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setView(MainView* view);
    ~MainWindow();

private slots:
    void onPositionChange();
    void onRotationChange();

    void on_actionLine_rotation_triggered();

    void on_actionPosition_triggered();

    void on_actionReset_triggered();

    void on_actionChange_color_triggered();

    void on_actionRandom_position_triggered();

private:
    Ui::MainWindow *ui;
    MainView* view;
    SetLineWindow *lineWindow;
    TurnObjectWindow *rotationWindow;

};

#endif // MAINWINDOW_H
