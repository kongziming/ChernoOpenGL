#include "Renderer.h"

Renderer::Renderer()
{

}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	shader.bind();
	va.bind();
	ib.bind();

	glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
