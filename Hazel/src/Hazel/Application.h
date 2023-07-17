#pragma once

#include "Core.h"
#include "Events/Event.h"// 包含事件基类

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


