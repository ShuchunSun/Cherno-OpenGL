#pragma once
#include <vector>
#include <string>
#include <functional>
#include <glad/glad.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace test 
{
	class Test
	{
	public:
		Test() {};
		virtual ~Test() {};

		virtual void onUpdate(float deltaTime) {};
		virtual void onRender() {};
		virtual void onImGuiRender() {};
	};

	class TestMenu :public Test
	{
	public:
		TestMenu(Test*& current);
		~TestMenu() {};

		void onImGuiRender() override;

		template<typename T>
		void registerTest(const std::string& name)
		{
			m_tests.push_back(std::make_pair(name, []() { return new T(); }));
		}

	private:
		Test*& m_currentTest;
		std::vector<std::pair<std::string, std::function<Test* ()>>> m_tests;
	};
}
