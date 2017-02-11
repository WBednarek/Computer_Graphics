#ifndef TURNOBJECTWINDOW_H
#define TURNOBJECTWINDOW_H

#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class TurnObjectWindow;
}

class TurnObjectWindow : public QDialog
{
    Q_OBJECT

public:
    ~TurnObjectWindow();
    QDialogButtonBox * getButton();
    explicit TurnObjectWindow(QWidget *parent = 0);
    //Get X, Y, Z of B
    vec3 getX_Y_Z_ValuesOf_B();
    //Get X, Y, Z of D
    vec3 getX_Y_Z_ValuesOf_D();
    //Get Phi value
    float getValueOfPhi();
private:
    Ui::TurnObjectWindow *ui;
};

#endif // TURNOBJECTWINDOW_H
