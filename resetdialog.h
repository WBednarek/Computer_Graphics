#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class ResetDialog;
}

class ResetDialog : public QDialog
{
    Q_OBJECT

public:
     QDialogButtonBox * getButton();
    explicit ResetDialog(QWidget *parent = 0);
    ~ResetDialog();

private:
    Ui::ResetDialog *ui;
};

#endif // RESETDIALOG_H
