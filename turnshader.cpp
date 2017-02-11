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
//Get X, Y, Z of B
vec3 TurnObjectWindow::getX_Y_Z_ValuesOf_B()
{
    auto xValOfB = this->ui->xB->value();
    auto yValOfB = this->ui->yB->value();
    auto zValOfB = this->ui->zB->value();
    return vec3(xValOfB, yValOfB, zValOfB);
}
//Get X, Y, Z of D
vec3 TurnObjectWindow::getX_Y_Z_ValuesOf_D()
{
    auto xValOfD = this->ui->xD->value();
    auto yValOfD = this->ui->yD->value();
    auto zValOfD = this->ui->zD->value();
    return vec3(xValOfD, yValOfD, zValOfD);
}

//Get Phi value
float TurnObjectWindow::getValueOfPhi()
{
    return this->ui->phi->value();
}
