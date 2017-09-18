#include <tchar.h>
#include <Windows.h>

#include "resource.h"

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
{
    // Создание главного окна приложения на основе модального диалога.
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure); 
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
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