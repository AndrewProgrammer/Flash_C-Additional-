#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*showCommand*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure);
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM /*lParam*/)
{
	HWND hButton[15];
	INT counter = 0;
	RECT r, r2;
	POINT p, p1;
	WCHAR str[256];
	switch (message)
	{
	case WM_INITDIALOG:
		for (int i = 0; i < 4; ++i)
		{
			_stprintf_s(str, L"%d", i + 1);
			hButton[i] = CreateWindowEx(0, L"BUTTON", str, WS_CHILD | WS_VISIBLE, i * 65, 1, 60, 60, window, (HMENU)(1500 + i), GetModuleHandle(0), 0);
		}
		for (int i = 0; i < 4; ++i)
		{
			_stprintf_s(str, L"%d", i + 5);
			hButton[i + 4] = CreateWindowEx(0, L"BUTTON", str, WS_CHILD | WS_VISIBLE, i * 65, 66, 60, 60, window, (HMENU)(1505 + i), GetModuleHandle(0), 0);
		}
		for (int i = 0; i < 4; ++i)
		{
			_stprintf_s(str, L"%d", i + 9);
			hButton[i + 9] = CreateWindowEx(0, L"BUTTON", str, WS_CHILD | WS_VISIBLE, i * 65, 131, 60, 60, window, (HMENU)(1509 + i), GetModuleHandle(0), 0);
		}
		for (int i = 0; i < 3; ++i)
		{
			_stprintf_s(str, L"%d", i + 13);
			hButton[i + 13] = CreateWindowEx(0, L"BUTTON", str, WS_CHILD | WS_VISIBLE, i * 65, 196, 60, 60, window, (HMENU)(1513 + i), GetModuleHandle(0), 0);
		}
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) >= 1500 && LOWORD(wParam) < 1515)
		{
			if (counter != 0)
			{
				GetWindowRect(hButton[LOWORD(wParam) % 1500], &r2);
				p1.x = r2.left;
				p1.y = r2.top;
			}
			if (counter == 0)
			{
				GetWindowRect(hButton[LOWORD(wParam) % 1500], &r);
				p.x = r.left;
				p.y = r.top;
			}
			if (counter != 0)
			{
				MoveWindow(hButton[counter % 1500], p1.x, p1.y, 60, 60, TRUE);
				MoveWindow(hButton[LOWORD(wParam) % 1500], p.x, p.y, 60, 60, TRUE);
			}
			if (counter == 0)
			{
				counter = LOWORD(wParam);
			}
		}
		return TRUE;
	case WM_CLOSE:
		EndDialog(window, 0);
		return TRUE;
	}
	return FALSE;
}