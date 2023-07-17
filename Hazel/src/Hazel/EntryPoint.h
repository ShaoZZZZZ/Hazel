#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {

	Hazel::Log::Init();
	Hazel::Log::GetClientLogger()->warn("Initialized Log!");
	Hazel::Log::GetCoreLogger()->info("Hello! Var={0}", 5);

	printf("ÄãºÃ£¬Çë¼ÓÓÍÑ½\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

}

#endif