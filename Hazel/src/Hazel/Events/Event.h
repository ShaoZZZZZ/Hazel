#pragma once

#include "Hazel/Core.h"
#include <functional>
#include <string>
#include <sstream>

namespace Hazel {

	// Events in Hazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	/*
	为了简便，自定义事件是立即处理事件，没有缓冲事件。
	缓冲事件：键盘a一直按下第一个立刻输出，顿了一下才一直输出。
	*/

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	// 事件分类-多个类一个分类，即多个类属于同一个分类
	#define BIT(x) (1 << x)
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	// 宏定义：每个子类都需要重写父类虚函数代码，可以用宏定义简洁代码
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;		// 获取本事件是哪个类型
		virtual const char* GetName() const = 0;		// 获取本事件的名称c字符数组
		virtual int GetCategoryFlags() const = 0;		// 获取本事件属于哪个分类
		virtual std::string ToString() const { return GetName(); }	// 获取本事件的名称从c字符数组转为字符串

		bool IsInCategory(EventCategory category)		// 判断本事件是否属于某个分类
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
