#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linedialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lDialog = new LineDialog(this);
    auto button = lDialog->getButton();
    connect(button, SIGNAL(accepted()), this, SLOT(onPositionChange()));

    rDialog = new RotationDialog(this);
    auto button2 = rDialog->getButton();
    connect(button2, SIGNAL(accepted()), this, SLOT(onRotationChange()));

}


void MainWindow::setView(MainView *view)
{
    this->view = view;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPositionChange()
{
    auto eyes = this->lDialog->getEye();
    auto direction = this->lDialog->getDirection();
    this->view->setLookAt(eyes, direction);
}

void MainWindow::onRotationChange()
{
    auto b = this->rDialog->getB();
    auto d = this->rDialog->getD();
    auto phi = this->rDialog->getPhi();

    this->view->rotateModel(b.x, b.y, b.z, d.x, d.y, d.z, phi);
}



void MainWindow::on_actionRot_45_about_y_triggered()
{
    view->setRotAxis(45,0,1,0);
}

void MainWindow::on_actionRot_45_about_x_triggered()
{
     view->setRotAxis(45,1,0,0);
}

void MainWindow::on_actionRot_45_about_z_triggered()
{
     view->setRotAxis(45,0,0,1);
}

void MainWindow::on_actionLine_rotation_triggered()
{
   lDialog ->show();
}

void MainWindow::on_actionPosition_triggered()
{
    rDialog->show();
}

void MainWindow::on_actionReset_triggered()
{
    this->view->setLookAt(vec3(0,0,2), vec3(0,0,-1));
    this->view->defaultDisplay();
}
