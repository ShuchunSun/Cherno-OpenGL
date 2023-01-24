#include "test.h"

namespace test
{
	TestMenu::TestMenu(Test*& current)
		: m_currentTest(current)
	{
	}

	void TestMenu::onImGuiRender()
	{
		glClearColor(0.0039f, 0.3019f, 0.4039f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		for (auto& test : m_tests)
		{
			if (ImGui::Button(test.first.c_str()))
			{
				m_currentTest = test.second();
			}
		}
	}
}