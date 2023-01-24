#include "vertexBufferLayout.h"

unsigned int VertexBufferElement::getSizeOfType(unsigned int type)
{
	switch (type)
	{
	case GL_FLOAT: return 4;
	case GL_UNSIGNED_INT: return 4;
	case GL_UNSIGNED_BYTE: return 1;
	}
	assert(false);
	return 0;
}

VertexBufferLayout::VertexBufferLayout()
	: m_stride(0)
{
}
