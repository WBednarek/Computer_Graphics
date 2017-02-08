#ifndef LINEDIALOG_H
#define LINEDIALOG_H

#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
#include <QDialog>
#include <QDialogButtonBox>
using glm::vec3;

namespace Ui {
class LineDialog;
}

class LineDialog : public QDialog
{
    Q_OBJECT

public:
    QDialogButtonBox * getButton();
    explicit LineDialog(QWidget *parent = 0);
    ~LineDialog();
    vec3 getEye();
    vec3 getDirection();
private slots:

    void on_buttonBox_accepted();

private:
    Ui::LineDialog *ui;
};

#endif // LINEDIALOG_H
