#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

/**
* @class VertexArray
* @brief 
* @details 描述
* @author 
*/
class VertexArray
{
public:
    VertexArray();

    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void bind() const;

    void unBind() const;

private:
    unsigned int m_rendererId;
};

#endif // VERTEX_ARRAY_H
