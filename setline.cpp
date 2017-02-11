#include "setline.h"
#include "ui_setline.h"

QDialogButtonBox *SetLineWindow::getButton()
{
    return this->ui->buttonBox;
}

SetLineWindow::SetLineWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetLineWindow)
{
    ui->setupUi(this);
}

SetLineWindow::~SetLineWindow()
{
    delete ui;
}
//Get eye position
vec3 SetLineWindow::getPositionOfEye()
{
    auto eyeX = this->ui->eyeX->value();
    auto eyeY = this->ui->eyeY->value();
    auto eyeZ = this->ui->eyeZ->value();
    return vec3(eyeX, eyeY, eyeZ);
}

//Get current direction
vec3 SetLineWindow::getCurrDirect()
{
    auto dirX = this->ui->dirX->value();
    auto dirY = this->ui->dirY->value();
    auto dirZ = this->ui->dirZ->value();
    return vec3(dirX, dirY, dirZ);
}

void SetLineWindow::on_buttonBox_accepted()
{

}
