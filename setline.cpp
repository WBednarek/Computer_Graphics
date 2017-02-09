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

glm::vec3 SetLineWindow::getEye()
{
    auto xEye = this->ui->xEye->value();
    auto yEye = this->ui->yEye->value();
    auto zEye = this->ui->zEye->value();
    return vec3(xEye, yEye, zEye);
}

glm::vec3 SetLineWindow::getDirection()
{
    auto xDirection = this->ui->xDirection->value();
    auto yDirection = this->ui->yDirection->value();
    auto zDirection = this->ui->zDirection->value();
    return vec3(xDirection, yDirection, zDirection);
}

void SetLineWindow::on_buttonBox_accepted()
{

}
