#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*showCommand*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure);
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM /*wParam*/, LPARAM lParam)
{
    BOOL result = TRUE;

    static HWND static1 = nullptr;
    static HWND static2 = nullptr;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
            // Данное сообщение приходит после создания диалогового окна, но перед его отображением.
        case WM_INITDIALOG:
            // Получение дескриптора элемента Static Text, размещенного на форме диалогового окна.
            static1 = GetDlgItem(window, IDC_STATIC1);

            // Программное создание элемента Static Text.
            static2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | SS_CENTERIMAGE, 10, 30, 250, 50, window, nullptr, GetModuleHandle(nullptr), nullptr);
            break;
        case WM_LBUTTONDOWN:
            SetWindowText(static2, TEXT("Left mouse button pressed"));
            break;
        case WM_MOUSEMOVE:
            {
                TCHAR coordinates[20] = {};

                // Текущие координаты курсора мыши.
                _stprintf_s(coordinates, TEXT("X: %d, Y: %d"), LOWORD(lParam), HIWORD(lParam));

                // Установка сформированной строки на элемент Static Text.
                SetWindowText(static1, coordinates);
            }
            break;
        case WM_RBUTTONDOWN:
            SetWindowText(static2, TEXT("Right mouse button pressed"));
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}