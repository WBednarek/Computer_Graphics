#include "resetdialog.h"
#include "ui_resetdialog.h"

QDialogButtonBox *ResetDialog::getButton()
{
    return this->ui->buttonBox;
}

ResetDialog::ResetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResetDialog)
{
    ui->setupUi(this);
}

ResetDialog::~ResetDialog()
{
    delete ui;
}
