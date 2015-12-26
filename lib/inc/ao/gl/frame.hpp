#pragma once

#include <list>

#include <glm/mat4x4.hpp>

#include "ao/gl/core.hpp"

/*
 *  The Frame class contains and draws many rendered Tree textures
 */
class Frame
{
public:
    explicit Frame();
    ~Frame();

    /*
     *  Draws the set of textures with the given matrix applied
     */
    void draw(const glm::mat4& m) const;

    /*
     *  Pushes a new render task to the stack at the given matrix
     */
    void push(const glm::mat4& m);

protected:
    GLuint vs;  // Vertex shader
    GLuint fs;  // Fragment shader
    GLuint prog;    // Shader program

    GLuint vbo; // Vertex buffer object
    GLuint vao; // Vertex array object

    // List of texture planes and the matrices with which they were rendered
    struct Tex
    {
        GLuint depth;
        GLuint normal;
    };
    std::list<std::pair<glm::mat4, Tex>> texs;


    // Shader source strings
    static const std::string vert;
    static const std::string frag;
};