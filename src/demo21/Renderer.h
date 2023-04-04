#ifndef RENDERER_H
#define RENDERER_H
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"

/**
* @class Renderer
* @brief 
* @details 描述
* @author 
*/
class Renderer
{
public:
    Renderer();

    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);

    void clear();
};

#endif // RENDERER_H
