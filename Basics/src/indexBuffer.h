#pragma once
#include <glad/glad.h>

class IndexBuffer
{
private:
	unsigned int m_ibo;
	unsigned int m_count;

public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return m_count; }
};

