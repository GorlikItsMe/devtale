#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#include "MainForm.h"

void WINAPI DllThread()
{
	AllocConsole();
	devtale::MainForm^ form = gcnew devtale::MainForm();
	System::Windows::Forms::Application::Run(form);
}

#pragma managed(push, off)
bool WINAPI DllMain(_In_ HINSTANCE instance, _In_ DWORD call_reason, _In_ LPVOID reserved)
{
	switch (call_reason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(DllThread), nullptr, 0, nullptr);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	default:
		break;
	}
	return TRUE;
}
#pragma managed(pop)
