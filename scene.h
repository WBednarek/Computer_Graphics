#ifndef SCENE_H
#define SCENE_H

#include "C:/glm/glm/glm.hpp"
using glm::vec3;

class Scene
{
public:
    /**
      Load textures, initialize shaders, etc.
      */
    virtual void initScene() = 0;

    /**
      This is called prior to every frame.  Use this
      to update your animation.
      */
    virtual void update( float t ) = 0;

    /**
      Draw your scene.
      */
    virtual void render() = 0;

    /**
      Called when screen is resized
      */
    virtual void resize(int, int) = 0;
    virtual void defaultDisplay() = 0;

    virtual void setLookAt(vec3 eye, vec3 direction) = 0;
    virtual void rotateModel(float bX, float bY, float bZ, float dX, float dY, float dZ, float phi) = 0;
};

#endif // SCENE_H
