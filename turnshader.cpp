#include "turnshader.h"
#include "ui_turnshader.h"

QDialogButtonBox *TurnObjectWindow::getButton()
{
    return this->ui->buttonBox;
}

TurnObjectWindow::TurnObjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TurnObjectWindow)
{
    ui->setupUi(this);
}

TurnObjectWindow::~TurnObjectWindow()
{
    delete ui;
}

glm::vec3 TurnObjectWindow::getB()
{
    auto xB = this->ui->xB->value();
    auto yB = this->ui->yB->value();
    auto zB = this->ui->zB->value();
    return vec3(xB, yB, zB);
}

glm::vec3 TurnObjectWindow::getD()
{
    auto xD = this->ui->xD->value();
    auto yD = this->ui->yD->value();
    auto zD = this->ui->zD->value();
    return vec3(xD, yD, zD);
}

float TurnObjectWindow::getPhi()
{
    return this->ui->phi->value();
}
