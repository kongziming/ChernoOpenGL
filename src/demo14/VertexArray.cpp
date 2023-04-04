#include "VertexArray.h"


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_rendererId);
	//glBindVertexArray(m_rendererId);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_rendererId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); ++i)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void *)offset);
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}
	
}

void VertexArray::bind() const
{
	glBindVertexArray(m_rendererId);
}

void VertexArray::unBind() const
{
	glBindVertexArray(0);
}
