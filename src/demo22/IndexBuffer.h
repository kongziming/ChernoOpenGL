#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

/**
* @class IndexBuffer
* @brief 
* @details 描述
* @author 
*/
class IndexBuffer
{
public:
    IndexBuffer(const unsigned int* data, unsigned int count);

    ~IndexBuffer();

    void bind() const;

    void unBind() const;

    inline unsigned int getCount() const
    {
        return m_count;
    }

private:
    unsigned int m_rendererId;
    unsigned int m_count;
};

#endif // INDEX_BUFFER_H
