#include "testTexture.h"

namespace test
{
	TestTexture::TestTexture()
		: m_translationA(200, 200, 0), m_translationB(400, 200, 0),
		m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
		m_view(glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0)))
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		std::string combinedShaderFilepath = "./res/shaders/texture.shader";
		std::string textureFilepath = "./res/textures/butterfly.png";

		float positions[] = {
			100.0f, 100.0f, 0.0f, 0.0f,
			200.0f, 100.0f, 1.0f, 0.0f,
			200.0f, 200.0f, 1.0f, 1.0f,
			100.0f, 200.0f, 0.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		m_ibo = std::make_unique<IndexBuffer>(indices, 6);

		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(2);
		m_vbo = std::make_unique<VertexBuffer>(positions, (unsigned int)sizeof(positions));

		m_vao = std::make_unique<VertexArray>();
		m_vao->addBuffer(*m_vbo, layout);

		m_shaderProgram = std::make_unique<ShaderProgram>(combinedShaderFilepath);
		m_texture = std::make_unique<Texture>(textureFilepath);
		m_shaderProgram->setUniform1i("u_texture", 0);
	}
	 
	TestTexture::~TestTexture()
	{
	}

	void TestTexture::onUpdate(float deltaTime)
	{
	}

	void TestTexture::onRender()
	{
		glClearColor(0.0039f, 0.3019f, 0.4039f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		m_texture->bind();
		Renderer renderer;

		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shaderProgram->setUniformMat4f("u_MVP", mvp);
			renderer.draw(*m_vao, *m_ibo, *m_shaderProgram);
		}

		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shaderProgram->setUniformMat4f("u_MVP", mvp);
			renderer.draw(*m_vao, *m_ibo, *m_shaderProgram);
		}

	}

	void TestTexture::onImGuiRender()
	{
		ImGui::SliderFloat3("TranslationA", &m_translationA.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("TranslationB", &m_translationB.x, 0.0f, 960.0f);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}

