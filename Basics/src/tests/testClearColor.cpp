#include "testClearColor.h"

namespace test
{
	TestClearColor::TestClearColor()
		: m_clearColor { 0.2f, 0.3f, 0.8f, 1.0f }
	{

	}

	TestClearColor::~TestClearColor()
	{
	}

	void TestClearColor::onUpdate(float deltaTime)
	{
	}

	void TestClearColor::onRender()
	{
		glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void TestClearColor::onImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_clearColor);
	}
}

