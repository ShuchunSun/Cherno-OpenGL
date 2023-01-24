#include "testBatchRender.h"

namespace test
{
	TestBatchRender::TestBatchRender()
		: m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f))
	{
		float positions[] = {
			140.0f, 170.0f, 0.0f, 0.3f, 0.8f, 0.2f, 1.0f,  0.0f, 0.0f, 0.0f,
			340.0f, 170.0f, 0.0f, 0.3f, 0.8f, 0.2f, 1.0f,  1.0f, 0.0f, 0.0f,
			340.0f, 370.0f, 0.0f, 0.3f, 0.8f, 0.2f, 1.0f,  1.0f, 1.0f, 0.0f,
			140.0f, 370.0f, 0.0f, 0.3f, 0.8f, 0.2f, 1.0f,  0.0f, 1.0f, 0.0f,

			620.0f, 170.0f, 0.0f, 0.8f, 0.1f, 0.5f, 1.0f,  0.0f, 0.0f, 1.0f,
			820.0f, 170.0f, 0.0f, 0.8f, 0.1f, 0.5f, 1.0f,  1.0f, 0.0f, 1.0f,
			820.0f, 370.0f, 0.0f, 0.8f, 0.1f, 0.5f, 1.0f,  1.0f, 1.0f, 1.0f,
			620.0f, 370.0f, 0.0f, 0.8f, 0.1f, 0.5f, 1.0f,  0.0f, 1.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			6, 7, 4
		};

		int samplers[2] = { 0, 1 };

		std::string combinedShaderFilepath = "./res/shaders/batch.shader";
		std::string textureGrassFilepath = "./res/textures/grass.jpg";
		std::string textureEarthFilepath = "./res/textures/earth.jpg";

		m_grassTexture = std::make_unique<Texture>(textureGrassFilepath);
		m_earthTexture = std::make_unique<Texture>(textureEarthFilepath);
		m_grassTexture->bind(0);
		m_earthTexture->bind(1);

		m_ibo = std::make_unique<IndexBuffer>(indices, 12);

		VertexBufferLayout layout;
		layout.push<float>(3);
		layout.push<float>(4);
		layout.push<float>(2);
		layout.push<float>(1);
		m_vbo = std::make_unique<VertexBuffer>(positions, (unsigned int)sizeof(positions));

		m_vao = std::make_unique<VertexArray>();
		m_vao->addBuffer(*m_vbo, layout);

		m_shaderProgram = std::make_unique<ShaderProgram>(combinedShaderFilepath);
		m_shaderProgram->setUniformMat4f("u_proj", m_proj);
		m_shaderProgram->setUniform1iv("u_texture", samplers);
	}
	 
	TestBatchRender::~TestBatchRender()
	{
	}

	void TestBatchRender::onUpdate(float deltaTime)
	{
	}

	void TestBatchRender::onRender()
	{
		glClearColor(0.0039f, 0.3019f, 0.4039f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		Renderer renderer;
		renderer.draw(*m_vao, *m_ibo, *m_shaderProgram);
	}

	void TestBatchRender::onImGuiRender()
	{
	}
}

