#include <ctime>
#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*showCommand*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure);
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
    BOOL result = TRUE;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
        case WM_INITDIALOG:
            SendMessage(GetDlgItem(window, IDC_SHOW_SECONDS), BM_SETCHECK, static_cast<WPARAM>(BST_CHECKED), 0U);

            SetTimer(window, 1U, 1000U, nullptr);
            break;
        case WM_TIMER:
            {
                static const HWND dateTime = GetDlgItem(window, IDC_DATE_TIME);
                static const HWND showSeconds = GetDlgItem(window, IDC_SHOW_SECONDS);

                const time_t currentTime = time(nullptr);
                TCHAR string[100] = {};

                tm timestamp = {};
                localtime_s(&timestamp, &currentTime);

                LRESULT lResult = SendMessage(showSeconds, BM_GETCHECK, 0U, 0U);
                if (lResult == BST_CHECKED)
                {
                    _tcsftime(string, ARRAYSIZE(string), TEXT("%H:%M:%S  %d.%m.%Y  %A"), &timestamp);
                }
                else
                {
                    _tcsftime(string, ARRAYSIZE(string), TEXT("%H:%M  %d.%m.%Y  %A"), &timestamp);
                }

                SetWindowText(dateTime, string);
            }
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}