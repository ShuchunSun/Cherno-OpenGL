#pragma once
#include <imgui/imgui.h>
#include <memory>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "test.h"
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shaderProgram.h"
#include "renderer.h"
#include "texture.h"

namespace test 
{
	class TestTexture :public Test
	{
	public:
		TestTexture();
		~TestTexture();

		void onUpdate(float deltaTime) override;
		void onRender() override;
		void onImGuiRender() override;

	private:
		glm::vec3 m_translationA;
		glm::vec3 m_translationB;

		std::unique_ptr<VertexArray> m_vao;
		std::unique_ptr<VertexBuffer> m_vbo;
		std::unique_ptr<IndexBuffer> m_ibo;
		std::unique_ptr<ShaderProgram> m_shaderProgram;
		std::unique_ptr<Texture> m_texture;

		glm::mat4 m_proj;
		glm::mat4 m_view;
	};
}


