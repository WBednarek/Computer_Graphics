#include "rotationdialog.h"
#include "ui_rotationdialog.h"

QDialogButtonBox *RotationDialog::getButton()
{
    return this->ui->buttonBox;
}

RotationDialog::RotationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RotationDialog)
{
    ui->setupUi(this);
}

RotationDialog::~RotationDialog()
{
    delete ui;
}

glm::vec3 RotationDialog::getB()
{
    auto xB = this->ui->xB->value();
    auto yB = this->ui->yB->value();
    auto zB = this->ui->zB->value();
    return vec3(xB, yB, zB);
}

glm::vec3 RotationDialog::getD()
{
    auto xD = this->ui->xD->value();
    auto yD = this->ui->yD->value();
    auto zD = this->ui->zD->value();
    return vec3(xD, yD, zD);
}

float RotationDialog::getPhi()
{
    return this->ui->phi->value();
}
