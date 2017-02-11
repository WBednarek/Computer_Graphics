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
    auto eyes = this->lineWindow->getPositionOfEye();
    auto direction = this->lineWindow->getCurrDirect();
    this->view->setLookAt(eyes, direction);
}

void MainWindow::onRotationChange()
{
    auto b = this->rotationWindow->getX_Y_Z_ValuesOf_B();
    auto d = this->rotationWindow->getX_Y_Z_ValuesOf_D();
    auto phi = this->rotationWindow->getValueOfPhi();

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


void MainWindow::on_actionRandom_position_triggered()
{
int time = 0;
int sleepTime = 30;
while(time < 1200)
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine dre(seed);
    std::uniform_real_distribution<float> gen(0, 200);

    int bx = gen(dre);
    int by = gen(dre);
    int bz = gen(dre);

    std::uniform_real_distribution<float> gen1(0, 180);
    int phi = gen1(dre);
   // this->view->setLookAt(vec3(0,0,2), vec3(0,0,-1));
    this->view->rotateModel(bx, by, bz, bx, by, bz, phi);
    Sleep(sleepTime);
    time += sleepTime;
}

}
