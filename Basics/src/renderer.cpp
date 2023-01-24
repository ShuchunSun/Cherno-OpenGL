#include "renderer.h"

void clearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

bool checkErrors()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << std::endl;
		return false;
	}
	return true;
}

void Renderer::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& sp) const
{
	va.bind();
	ib.bind();
	sp.bind();

	glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
	return;
}
