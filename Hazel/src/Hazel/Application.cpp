#include "Application.h"
#include "Events/ApplicationEvent.h" // ���������¼�
#include "Log.h"

namespace Hazel {
	Application::Application() {}
	Application::~Application() {}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);	// ʹ���Զ����¼�
		if (e.IsInCategory(EventCategoryApplication))	// �ж��Ƿ��Ӧ�ķ���
		{
			//HZ_TRACE(e);	// ����¼�
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			//HZ_TRACE(e);
		}
		while (true);
	}
}
