#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "C:/glew-1.13.0/include/GL/glew.h"
#include "C:/glm/glm/glm.hpp"
#include <QGLWidget>
#include <QTimer>
using glm::vec3;
#include "scene.h"

class MainView : public QGLWidget
{
    Q_OBJECT

private:
    QTimer *timer;
    Scene *scene;
    float angle;
    vec3 axis;

public:
    MainView( const QGLFormat & format, QWidget *parent = 0 );
    void resetModel();
    void rotateModel(float bX, float bY, float bZ, float dX, float dY, float dZ, float phi);
    void changePosition(vec3 eye, vec3 direction);
    void setRotAxis(float ang, float x, float y , float z);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void timerUpdate();
    void toggleAnimation();
    void takeScreenShot();
};

#endif // MAINVIEW_H
