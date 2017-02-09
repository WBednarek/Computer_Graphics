#include "scenebasic.h"

#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <fstream>
using std::ifstream;

#include <sstream>
using std::ostringstream;

#include "glutils.h"
#include "C:/glm/glm/gtc/matrix_transform.hpp"
//#include "C:/glm/glm/gtc/matrix_projection.hpp"
#include "C:/glm/glm/gtx/transform2.hpp"


SceneBasic::SceneBasic() : isObjectRotated(false)
{
    readData("shader/scenebasic2.dat");

    initializeSet();
}

bool SceneBasic::getIsObjectRotated() const
{
    return isObjectRotated;
}

void SceneBasic::setIsObjectRotated(bool value)
{
    isObjectRotated = value;
}

void SceneBasic::initializeSet()
{
    srand(time(NULL));
    float initialPosition = rand() % 8;
    std::cout<<"Random number is: "<<initialPosition<<" number of loop iteration: "
             <<sizeof(axisData) / sizeof(axisData[0])<<std::endl;

    for (int i = 0; i < sizeof(axisData) / sizeof(axisData[0]); ++i)
    {
         axisData[i] = initialPosition;
         axisColData[i] = 1;
    }

}


void SceneBasic::readData(const char* fname)
{
    ifstream ifs(fname);

    if (!ifs) {
        std::cout << "data file not found\n";
        std::cout << "Communicate: "<<ifs.get()<<std::endl;
        exit(1);
    } else {
        for (int i=0; i<108; i++) ifs >> positionData[i];
        for (int i=0; i<108; i++) ifs >> colorData[i];
    }
}

void SceneBasic::CreateVBO( GLuint * vaoHandle, float pos[], float colorData[], int newSize )
{
    // Create and populate the buffer objects
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);

    GLuint positionBufferHandle = vboHandles[0];
    GLuint colorBufferHandle = vboHandles[1];

    // bind positionBufferHandle to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, newSize * sizeof(float), pos, GL_STATIC_DRAW);


     // bind colorBufferHandle to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, newSize * sizeof(float), colorData, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    glGenVertexArrays( 1, vaoHandle );
    // bind the vertex array object
    glBindVertexArray(*vaoHandle);

    /* enables the generic vertex attribute array
       the values in the generic vertex attribute array will be accessed
       and used for rendering when calls are made to vertex array commands
       such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);

    /* define an array of generic vertex attribute data
       specifies the location and data format of the array of generic
       vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void SceneBasic::initScene()
{
    //////////////////////////////////////////////////////
    /////////// Vertex shader //////////////////////////
    //////////////////////////////////////////////////////

    /* The OpenGL Extension Wrangler Library (GLEW) is a cross-platform
     open-source C/C++ extension loading library. GLEW provides efficient
     run-time mechanisms for determining which OpenGL extensions are supported
     on the target platform.

     if you link with some function - it must exist on target platform,
     or your program wouldn't launch. GLEW handles that - you're not linking
     with GL functions directly, but instead getting function pointers after
     initialization phase. It allows you to check at runtime which extensions
     are present and which functions may be used.

     GLEW obtains information on the supported extensions from the graphics driver.
     Experimental or pre-release drivers, however, might not report every available
     extension through the standard mechanism, in which case GLEW will report
     it unsupported. To circumvent this situation, the glewExperimental global switch
     can be turned on by setting it to GL_TRUE before calling glewInit(), which ensures
     that all extensions with valid entry points will be exposed. */

    glewExperimental = GL_TRUE;
    glewInit();

    // Create the vertex shader object
    GLuint vertShader = prog.createShader(GL_VERTEX_SHADER);

    // Check status
    if( 0 == vertShader)
    {
        fprintf(stderr, "Error creating vertex shader.\n");
        exit(1);
    }

    // load the shader from the file
    prog.load_shader(vertShader,"shader/basic.vert");

    // compile the shader
    prog.compileShader(vertShader);

    // Check compilation status
    prog.checkCompileStatus(vertShader);


    //////////////////////////////////////////////////////
    /////////// Fragment shader //////////////////////////
    //////////////////////////////////////////////////////


   // Create the fragment shader object
    GLuint fragShader = prog.createShader(GL_FRAGMENT_SHADER);

    // Check status
    if( 0 == fragShader)
    {
        fprintf(stderr, "Error creating fragment shader.\n");
        exit(1);
    }

    // load the shader from the file
    prog.load_shader(fragShader,"shader/basic.frag");

    // compile the shader
    prog.compileShader(fragShader);

    // Check compilation status
    prog.checkCompileStatus(fragShader);

    // Create the program object
    if (!prog.createObject()) printf("error\n");

    // attach shaders to program object
    prog.attachShader(vertShader);
    prog.attachShader(fragShader);

    // Bind index 0 to the shader input variable "VertexPosition"
    prog.bindAttribLocation(0, "VertexPosition");
    // Bind index 1 to the shader input variable "VertexColor"
    prog.bindAttribLocation(1, "VertexColor");

    // link the program
    prog.link();

    // create and populate the vertex buffer opbject
    CreateVBO( &vaoHandle, positionData, colorData, 108 );

    //  create and populate the vertex buffer opbject for line object
    CreateVBO( &axisVaoHandle, axisData, axisColData, 6 );

    prog.printActiveUniforms();

    model = mat4(1.0f);

    view = glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3(0.0f,0.0f,0.0f), vec3(0.0f,1.0f,0.0f));
    projection = mat4(1.0f);

    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glEnable(GL_DEPTH_TEST);
}


void SceneBasic::update( float t )
{
    angle += t*2*PI/360.0;
    if( t >= 360.0) angle -= 360.0;
}


void SceneBasic::setMatrices()
{
  //  rotationMatrix = glm::rotate(mat4(1.0f),angle,vec3(0.0f,1.0f,0.0f));
    //model = glm::rotate(mat4(1.0f),angle,axis);
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("MVP", projection * mv);
}


void SceneBasic::resize(int w, int h)
{
    glViewport(0,0,w,h);
    width = w;
    height = h;
    projection = glm::perspective((float)PI/6, (float)w/h, 0.3f, 30.0f);
}


void SceneBasic::render()
{

    /* sets the bitplane area of the window to values previously
       selected by glClear. GL_COLOR_BUFFER_BIT indicates the buffers
       currently enabled for color writing. */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* render primitives from array data
       GL_TRIANGLES Specifies what kind of primitives to render.
       Possibilities are symbolic constants GL_POINTS, GL_LINE_STRIP,
       GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN and GL_TRIANGLES.
       0 specifies the starting index in the enabled arrays.
       36 specifies the number of indices to be rendered. */

    // bind the vertex array object
    glBindVertexArray(vaoHandle);

    // set matrices
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("MVP", projection * mv);

    glDrawArrays(GL_TRIANGLES, 0, 36 );

    if ( getIsObjectRotated() == true )
    {
        //size axis is 6
        CreateVBO( &axisVaoHandle, axisData, axisColData, 6 );
        glBindVertexArray(axisVaoHandle);

        prog.setUniform("ModelViewMatrix", view);
        prog.setUniform("MVP", projection * view);

        glDrawArrays(GL_LINES, 0, 2);
    }
}

void SceneBasic::printActiveUniforms(GLuint programHandle) {

    GLint nUniforms, size, location, maxLen;
    GLchar * name;
    GLsizei written;
    GLenum type;

    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

    name = (GLchar *) malloc( maxLen );

    printf(" Location | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nUniforms; ++i ) {
        glGetActiveUniform( programHandle, i, maxLen, &written, &size, &type, name );
        location = glGetUniformLocation(programHandle, name);
        printf(" %-8d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::printActiveAttribs(GLuint programHandle) {

    GLint written, size, location, maxLength, nAttribs;
    GLenum type;
    GLchar * name;

    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &nAttribs);

    name = (GLchar *) malloc( maxLength );

    printf(" Index | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nAttribs; i++ ) {
        glGetActiveAttrib( programHandle, i, maxLength, &written, &size, &type, name );
        location = glGetAttribLocation(programHandle, name);
        printf(" %-5d | %s\n",location, name);
    }

    free(name);
}



void SceneBasic::rotateModel(float bX, float bY, float bZ, float dX, float dY, float dZ, float phi)
{

    //Definicion of needed rotation matrices and vectors
    mat4 matrixTranslation1;
    mat4 matrixTranslation2;
    mat4 matrixRotation;
    vec3 bVector1(bX, bY, bZ);
    vec3 bVector2(-bX, -bY, -bZ);
    vec3 dVector(dX, dY, dZ);
    //Variable to store result of M2translation * Mrotation * M1translation
    mat4 model;


    //Performing M1translation
    matrixTranslation1 = glm::translate(mat4(1.f),bVector1 );

    //Performing M2translation
    matrixTranslation2 = glm::translate(mat4(1.f), bVector2);

    //Matrix of rotation Mrotation
    matrixRotation = glm::rotate((float) (phi*PI / 180), dVector);

    //Calculating M2translation * Mrotation * M1translation
   model = matrixTranslation2 * matrixRotation * matrixTranslation1;

    //Settiing variavle and storing result of M2translation * Mrotation * M1translation
    this->model = this->model * model;

   setAxis( bX, bY,  bZ,  dX,  dY,  dZ);
   //Rotation flag
    setIsObjectRotated(true);
}


void SceneBasic::setLookAt(glm::vec3 eye, glm::vec3 direct)
{
    this->view = glm::lookAt(vec3(eye.x,eye.y,eye.z),
                             vec3(eye.x+direct.x, eye.y+direct.y, eye.z+direct.z),
                             vec3(0.0f,1.0f,0.0f));
}



void SceneBasic::setAxis(float bX, float bY, float bZ, float dX, float dY, float dZ)
{
axisData[0] = bX;
axisData[1] = bY;
axisData[2] = bZ;
axisData[3] = bX+dX;
axisData[4] = bY+dY;
axisData[5] = bZ+dZ;
}

void SceneBasic::defaultDisplay()
{
    this->model = mat4(1.0f);
}

void SceneBasic::newLineColor()
{
    //Modern way of generating random numbers
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine dre(seed);
    std::uniform_real_distribution<float> gen(0, 1);

    //srand(time(NULL));
    // float newColor =  ((float) rand() / (RAND_MAX));

    for (int i = 0; i < sizeof(axisData) / sizeof(axisData[0]); ++i)
    {
         float newColor = gen(dre);
         axisColData[i] = newColor;
    }

}
