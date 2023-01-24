#include "shaderProgram.h"

ShaderProgram::ShaderProgram(const std::string& filepath)
	: m_filepath(filepath), m_shaderProgramID(0)
{
	ShaderSource shaderSource(filepath);
	m_shaderProgramID = createShaderProgram(shaderSource.vertexShaderSource(), shaderSource.fragmentShaderSource());
	glUseProgram(m_shaderProgramID);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_shaderProgramID);
}

void ShaderProgram::bind() const
{
	glUseProgram(m_shaderProgramID);
}

void ShaderProgram::unbind() const
{
	glUseProgram(0);
}

void ShaderProgram::setUniform1i(const std::string& name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void ShaderProgram::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

void ShaderProgram::setUniform1iv(const std::string& name, const int* vec)
{
	glUniform1iv(getUniformLocation(name), 2, vec);
}

void ShaderProgram::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

int ShaderProgram::getUniformLocation(const std::string& name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
	{
		return m_uniformLocationCache[name];
	}

	int location = glGetUniformLocation(m_shaderProgramID, name.c_str());
	if (location == -1)
	{
		std::cout << "Warning: uniform '" << name << "' doesn't exist!";
	}

	m_uniformLocationCache[name] = location;
	return location;
}

unsigned int ShaderProgram::compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// Error Handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Failed to compile shader!" << std::endl;
		std::cout << message << std::endl;

		if (message != nullptr)
		{
			delete[] message;
			message = nullptr;
		}

		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int ShaderProgram::createShaderProgram(const std::string& vertSrc, const std::string& fragSrc)
{
	unsigned int program = glCreateProgram();
	unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertSrc);
	unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragSrc);
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}
