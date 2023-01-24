#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class ShaderSource
{
private:
	std::string m_vertexShaderSource;
	std::string m_fragmentShaderSource;

public:
	ShaderSource(std::string shaderFilepath);
	ShaderSource(std::string vertFilepath, std::string fragFilepath);

	inline std::string vertexShaderSource() { return m_vertexShaderSource; }
	inline std::string fragmentShaderSource() { return m_fragmentShaderSource; }
};
