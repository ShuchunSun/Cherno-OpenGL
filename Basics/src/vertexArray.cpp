#include "vertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_vao);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_vao);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	this->bind();
	vb.bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);
		glEnableVertexAttribArray(i);
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(m_vao);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
