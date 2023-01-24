#pragma once
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shaderProgram.h"

void clearErrors();
bool checkErrors();

class Renderer
{
public:
	void clear() const;
	void draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& sp) const;
};

