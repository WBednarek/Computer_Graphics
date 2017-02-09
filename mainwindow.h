#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainview.h"
#include "linedialog.h"
#include "rotationdialog.h"

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


    void on_actionRot_45_about_y_triggered();

    void on_actionRot_45_about_x_triggered();

    void on_actionRot_45_about_z_triggered();

    void on_actionLine_rotation_triggered();

    void on_actionPosition_triggered();

    void on_actionReset_triggered();

private:
    Ui::MainWindow *ui;
    MainView* view;
    LineDialog *lDialog;
    RotationDialog *rDialog;

};

#endif // MAINWINDOW_H
