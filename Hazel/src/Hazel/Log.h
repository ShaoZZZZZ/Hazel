#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel {

	class HAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger; // static pointer to spdlog logger
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


