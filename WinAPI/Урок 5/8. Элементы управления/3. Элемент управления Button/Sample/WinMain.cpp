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
    BOOL result = TRUE;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
        // Данное сообщение приходит при нажатии на кнопку.
        case WM_COMMAND:
            {
                static const HWND start = GetDlgItem(window, IDC_START);
                static const HWND stop = GetDlgItem(window, IDC_STOP);

                switch (LOWORD(wParam))
                {
                    case IDC_START:
                        SetTimer(window, 1U, 50U, nullptr);

                        EnableWindow(start, FALSE);
                        EnableWindow(stop, TRUE);
                        break;
                    case IDC_STOP:
                        KillTimer(window, 1U);

                        EnableWindow(start, TRUE);
                        EnableWindow(stop, FALSE);
                        break;
                }
            }
            break;
        case WM_TIMER:
            {
                static const HWND counter = GetDlgItem(window, IDC_COUNTER);

                TCHAR text[10] = {};
                GetWindowText(counter, text, ARRAYSIZE(text));

                _itot_s(_ttoi(text) + 1, text, 10);

                SetWindowText(counter, text);
            }
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}