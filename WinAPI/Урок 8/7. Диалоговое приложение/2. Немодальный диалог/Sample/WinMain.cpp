#include <tchar.h>
#include <Windows.h>

#include "resource.h"

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogProcedure3(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/);
BOOL CALLBACK DialogProcedure2(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT showCommand)
{
	// Создание главного окна приложения на основе немодального диалога.
	HWND dialog = CreateDialog(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure);

	ShowWindow(dialog, showCommand);

	MSG message = {};

	while (GetMessage(&message, nullptr, 0U, 0U))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	BOOL result = TRUE;

	switch (message)
	{
	case WM_LBUTTONDOWN:
		DialogBox(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDD_DIALOG), window, DialogProcedure2);//Создаем новый диалог
		break;
	case WM_RBUTTONDOWN:
	{
		HWND Dialog = CreateDialog(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDD_DIALOG), window, DialogProcedure3);//Создаем новый диалог
		ShowWindow(Dialog, SW_SHOW);
		break;
	}
	case WM_CLOSE:
		// Разрушение окна.
		DestroyWindow(window);
		break;
	case WM_DESTROY:
		// Остановка цикла обработки сообщений.
		PostQuitMessage(0);
		break;
	default:
		result = FALSE;
		break;
	}

	return result;
}
BOOL CALLBACK DialogProcedure2(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	BOOL result = TRUE;

	switch (message)
	{
	case WM_CLOSE:
		// Закрытие модального диалога.
		EndDialog(window, 0);
		break;
	default:
		result = FALSE;
		break;
	}

	return result;
}
BOOL CALLBACK DialogProcedure3(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	BOOL result = TRUE;

	switch (message)
	{
	case WM_CLOSE:
		// Закрытие модального диалога.
		DestroyWindow(window);
		break;
	default:
		result = FALSE;
		break;
	}

	return result;
}