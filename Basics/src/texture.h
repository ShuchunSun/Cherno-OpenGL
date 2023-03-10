#pragma once
#include <string>
#include <glad/glad.h>

class Texture
{
private:
	unsigned int m_textureID;
	std::string m_filepath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_bitPerPixel;

public:
	Texture(const std::string& path);
	~Texture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }

};

