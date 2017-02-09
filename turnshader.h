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
    QDialogButtonBox * getButton();
    explicit TurnObjectWindow(QWidget *parent = 0);
    ~TurnObjectWindow();
    vec3 getB();
    vec3 getD();
    float getPhi();
private:
    Ui::TurnObjectWindow *ui;
};

#endif // TURNOBJECTWINDOW_H
