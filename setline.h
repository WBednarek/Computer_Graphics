#ifndef SETLINEWINDOW_H
#define SETLINEWINDOW_H

#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
#include <QDialog>
#include <QDialogButtonBox>
using glm::vec3;

namespace Ui {
class SetLineWindow;
}

class SetLineWindow : public QDialog
{
    Q_OBJECT

public:
    QDialogButtonBox * getButton();
    explicit SetLineWindow(QWidget *parent = 0);
    ~SetLineWindow();
    vec3 getEye();
    vec3 getDirection();
private slots:

    void on_buttonBox_accepted();

private:
    Ui::SetLineWindow *ui;
};

#endif // SETLINEWINDOW_H
