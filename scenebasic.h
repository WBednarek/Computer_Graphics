#ifndef SCENEBASIC_H
#define SCENEBASIC_H

#include "scene.h"
#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
using glm::mat4;

class SceneBasic : public Scene
{
private:
    int width, height;
    GLuint vboHandles[2];
    GLuint vaoHandle;
    float angle;
    vec3 axis;
    mat4 rotationMatrix;
    GLSLProgram prog;

    mat4 model;
    mat4 view;
    mat4 projection;

    void readData(const char* fname);
    void CreateVBO();

    float positionData[108];
    float colorData[108];
public:
    SceneBasic();
    void setMatrices();

    void initScene();
    void render();
    void resize(int, int);
    void update( float t );
    void setAngleAxis(float ang, vec3 ax);

    void printActiveUniforms(GLuint programHandle);
    void printActiveAttribs(GLuint programHandle);
    virtual void rotateModel(float bX, float bY, float bZ, float dX, float dY, float dZ, float phi);
     void SceneBasic::setLookAt(vec3 eye, vec4 direction);
};

#endif // SCENEBASIC_H
