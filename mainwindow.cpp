#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setline.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lineWindow = new SetLineWindow(this);
    auto button = lineWindow->getButton();
    connect(button, SIGNAL(accepted()), this, SLOT(onPositionChange()));

    rotationWindow = new TurnObjectWindow(this);
    auto button2 = rotationWindow->getButton();
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
    auto eyes = this->lineWindow->getEye();
    auto direction = this->lineWindow->getDirection();
    this->view->setLookAt(eyes, direction);
}

void MainWindow::onRotationChange()
{
    auto b = this->rotationWindow->getB();
    auto d = this->rotationWindow->getD();
    auto phi = this->rotationWindow->getPhi();

    this->view->rotateModel(b.x, b.y, b.z, d.x, d.y, d.z, phi);
}



void MainWindow::on_actionLine_rotation_triggered()
{
   lineWindow ->show();
}

void MainWindow::on_actionPosition_triggered()
{
    rotationWindow->show();
}

void MainWindow::on_actionReset_triggered()
{
    this->view->setLookAt(vec3(0,0,2), vec3(0,0,-1));
    this->view->defaultDisplay();
}

void MainWindow::on_actionChange_color_triggered()
{
    this->view->newLineColor();
}
