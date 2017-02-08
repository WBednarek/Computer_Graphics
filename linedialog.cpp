#include "linedialog.h"
#include "ui_linedialog.h"

QDialogButtonBox *LineDialog::getButton()
{
    return this->ui->buttonBox;
}

LineDialog::LineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineDialog)
{
    ui->setupUi(this);
}

LineDialog::~LineDialog()
{
    delete ui;
}

glm::vec3 LineDialog::getEye()
{
    auto xEye = this->ui->xEye->value();
    auto yEye = this->ui->yEye->value();
    auto zEye = this->ui->zEye->value();
    return vec3(xEye, yEye, zEye);
}

glm::vec3 LineDialog::getDirection()
{
    auto xDirection = this->ui->xDirection->value();
    auto yDirection = this->ui->yDirection->value();
    auto zDirection = this->ui->zDirection->value();
    return vec3(xDirection, yDirection, zDirection);
}

void LineDialog::on_buttonBox_accepted()
{

}
