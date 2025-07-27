
#include <Hazel.h>
#include "imgui/imgui.h"

class ExampleLayer : public Hazel::Layer
{

public:

	ExampleLayer()
		: Layer("Example")
	{		
	}

	void OnUpdate() override
	{
		//HZ_INFO("ExampleLayer::OnUpdate");

		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("Tab key is pressed");
	}

	void OnEvent(Hazel::Event& event) override
	{
		// HZ_TRACE("{0}", event);
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("Tab key pressed (event)");
			HZ_TRACE("KeyPressed: {0}", (char)e.GetKeyCode());
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Example Layer");
		ImGui::Text("Hello from ExampleLayer!");
		ImGui::End();
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}

