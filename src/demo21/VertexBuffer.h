#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

/**
* @class VertexBuffer
* @brief 
* @details 描述
* @author 
*/
class VertexBuffer
{
public:
    VertexBuffer(const void* data, unsigned int size);

    ~VertexBuffer();

    void bind() const;

    void unBind() const;

private:
    unsigned int m_rendererId;
};

#endif // VERTEX_BUFFER_H
