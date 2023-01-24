#pragma once
#include <unordered_map>
#include <glad/glad.h>
#include "shaderSource.h"
#include "glm/glm.hpp"

class ShaderProgram
{
private:
	unsigned int m_shaderProgramID;
	std::string m_filepath;
	std::unordered_map<std::string, int> m_uniformLocationCache;

public:
	ShaderProgram(const std::string& filepath);
	~ShaderProgram();

	void bind() const;
	void unbind() const;

	void setUniform1i(const std::string& name, int value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniform1iv(const std::string& name, const int* vec);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
	int getUniformLocation(const std::string& name);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int createShaderProgram(const std::string& vertSrc, const std::string& fragSrc);
};

