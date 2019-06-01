#include <Windows.h>
#include "Includes.h"
#include "Menu.h"
#include "Keyboard.h"
#include "Items.h"
#include "Colors.h"
#include "EnableDebug.h"
#include "Hacks.h"
#include "DrawMenu.h"


BOOL APIENTRY DllMain(HMODULE hmodule, DWORD ui_reason_for_call, LPVOID lpReserved)
{
	EnableDebugPrivilege();
	if (ui_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DrawMenu();
	}
	return true;
}