#ifndef ROTATIONDIALOG_H
#define ROTATIONDIALOG_H

#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class RotationDialog;
}

class RotationDialog : public QDialog
{
    Q_OBJECT

public:
    QDialogButtonBox * getButton();
    explicit RotationDialog(QWidget *parent = 0);
    ~RotationDialog();
    vec3 getB();
    vec3 getD();
    float getPhi();
private:
    Ui::RotationDialog *ui;
};

#endif // ROTATIONDIALOG_H
