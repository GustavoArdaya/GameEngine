#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent resizeEvent(1280, 720);
		HZ_TRACE(resizeEvent.ToString());

		while (true);
	}
}


