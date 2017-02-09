#ifndef SCENEBASIC_H
#define SCENEBASIC_H

#include "scene.h"
#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
#include <vector>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <random>
using glm::mat4;

class SceneBasic : public Scene
{
private:
    int width, height;
    GLuint vboHandles[2];
    GLuint axisVaoHandle;
    GLuint vaoHandle;
    float angle;
    vec3 axis;
    mat4 rotationMatrix;
    GLSLProgram prog;
    bool isObjectRotated;

    mat4 model;
    mat4 view;
    mat4 projection;

    void readData(const char* fname);
    void CreateVBO( GLuint * vaoHandle, float positionData[], float colorData[], int newSize );

    float positionData[108];
    float colorData[108];
    float axisData[10];
    std::vector<float> axisData0;
    float axisColData[10];
    const double PI = 4.0*atan(1.0);
public:
    void setLookAt(vec3 eye, vec3 direction);
    void rotateModel(float bX, float bY, float bZ, float dX, float dY, float dZ, float phi);
    void defaultDisplay();
    void setAxis(float bX, float bY, float bZ, float dX, float dY, float dZ);
    void initializeSet();


    SceneBasic();
    void setMatrices();

    void initScene();
    void render();
    void resize(int a, int b);
    void update( float t );
    void printActiveUniforms(GLuint programHandle);
    void printActiveAttribs(GLuint programHandle);
    bool getIsObjectRotated() const;
    void setIsObjectRotated(bool value);
    void newLineColor();
};

#endif // SCENEBASIC_H
