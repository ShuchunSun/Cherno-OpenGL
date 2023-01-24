#include "shaderSource.h"

ShaderSource::ShaderSource(std::string shaderFilepath)
{
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1,
	};

	std::ifstream ifs;
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	ifs.open(shaderFilepath.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Failed to open shader file" << std::endl;
	}
	while (getline(ifs, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	m_vertexShaderSource = ss[0].str();
	m_fragmentShaderSource = ss[1].str();

	ifs.close();
}

ShaderSource::ShaderSource(std::string vertFilepath, std::string fragFilepath)
{
	std::ifstream ifs;
	char line[1024] = { 0 };

	ifs.open(vertFilepath.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Failed to open vertex shader file" << std::endl;
	}
	while (ifs.getline(line, sizeof(line)))
	{
		m_vertexShaderSource.append(line);
		m_vertexShaderSource.append("\n");
	}
	ifs.close();

	ifs.open(fragFilepath.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Failed to open fragment shader file" << std::endl;
	}
	while (ifs.getline(line, sizeof(line)))
	{
		m_fragmentShaderSource.append(line);
		m_fragmentShaderSource.append("\n");

	}
	ifs.close();
}
