#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure); 
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM /*lParam*/)
{
    BOOL result = TRUE;

    static HWND enter = nullptr;
    static HWND login = nullptr;
    static HWND password = nullptr;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
        case WM_COMMAND:
            {
                static TCHAR loginString[20] = {};
                static TCHAR passwordString[20] = {};

                TCHAR text[100] = {};

                if (LOWORD(wParam) == IDC_LOGIN || LOWORD(wParam) == IDC_PASSWORD)
                {
                    if (HIWORD(wParam) == EN_CHANGE)
                    {
                        GetWindowText(login, loginString, ARRAYSIZE(loginString));
                        GetWindowText(password, passwordString, ARRAYSIZE(passwordString));

                        if (_tcslen(loginString) == 0U || _tcslen(passwordString) < 6U)
                        {
                            EnableWindow(enter, FALSE);
                        }
                        else
                        {
                            EnableWindow(enter, TRUE);
                        }
                    }
                }
                else if (LOWORD(wParam) == IDC_ENTER)
                {
                    _stprintf_s(text, TEXT("Login: %s\nPassword: %s"), loginString, passwordString);

                    MessageBox(window, text, TEXT("Authorization"), MB_OK | MB_ICONINFORMATION);

                    SetWindowText(login, nullptr);
                    SetWindowText(password, nullptr);

                    SetFocus(login);

                    EnableWindow(enter, FALSE);
                }
            }
            break;
        case WM_INITDIALOG:
            enter = GetDlgItem(window, IDC_ENTER);
            login = GetDlgItem(window, IDC_LOGIN);
            password = GetDlgItem(window, IDC_PASSWORD);
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}