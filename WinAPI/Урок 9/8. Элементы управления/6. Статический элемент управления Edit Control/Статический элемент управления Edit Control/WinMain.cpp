#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure); 
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM /*lParam*/)
{
    BOOL result = TRUE;

    static HWND login = nullptr;
    static HWND password = nullptr;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
        case WM_COMMAND:
            if (LOWORD(wParam) == IDC_ENTER)
            {
                TCHAR loginString[20] = {};
                TCHAR passwordString[20] = {};
                TCHAR text[100] = {};

                GetWindowText(login, loginString, ARRAYSIZE(loginString));
                GetWindowText(password, passwordString, ARRAYSIZE(passwordString));

                if (_tcslen(loginString) == 0U || _tcslen(passwordString) == 0U)
                {
                    MessageBox(window, TEXT("You must enter login and password"), TEXT("Authorization"), MB_OK | MB_ICONSTOP);
                }
                else
                {
                    _stprintf_s(text, TEXT("Login: %s\nPassword: %s"), loginString, passwordString);

                    MessageBox(window, text, TEXT("Authorization"), MB_OK | MB_ICONINFORMATION);
                }

                SetWindowText(login, nullptr);
                SetWindowText(password, nullptr);

                SetFocus(login);
            }
            break;
        case WM_INITDIALOG:
            login = GetDlgItem(window, IDC_LOGIN);
            password = GetDlgItem(window, IDC_PASSWORD);
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}