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
        case WM_COMMAND:
            if (LOWORD(wParam) >= IDC_COLOR_RED && LOWORD(wParam) <= IDC_LANGUAGE_UKRAINIAN)
            {
                TCHAR string[20] = {};
                _stprintf_s(string, TEXT("Radio button %d"), LOWORD(wParam) - IDC_COLOR_RED + 1);

                SetWindowText(window, string);
            }
            else if (LOWORD(wParam) == IDC_SHOW_CHOSEN)
            {
                TCHAR string[100] = TEXT("These radio buttons are chosen:\n");

                LRESULT lResult = SendDlgItemMessage(window, IDC_COLOR_RED, BM_GETCHECK, 0U, 0U); //Дескриптор и айдишник
                if (lResult == BST_CHECKED)
                {
                    _tcscat_s(string, TEXT("Red\n"));
                }
                else
                {
                    lResult = SendDlgItemMessage(window, IDC_COLOR_GREEN, BM_GETCHECK, 0U, 0U);
                    if (lResult == BST_CHECKED)
                    {
                        _tcscat_s(string, TEXT("Green\n"));
                    }
                    else
                    {
                        lResult = SendDlgItemMessage(window, IDC_COLOR_BLUE, BM_GETCHECK, 0U, 0U);
                        if (lResult == BST_CHECKED)
                        {
                            _tcscat_s(string, TEXT("Blue\n"));
                        }
                    }
                }

                lResult = SendDlgItemMessage(window, IDC_LANGUAGE_ENGLISH, BM_GETCHECK, 0U, 0U);
                if (lResult == BST_CHECKED)
                {
                    _tcscat_s(string, TEXT("English\n"));
                }
                else
                {
                    lResult = SendDlgItemMessage(window, IDC_LANGUAGE_RUSSIAN, BM_GETCHECK, 0U, 0U);
                    if (lResult == BST_CHECKED)
                    {
                        _tcscat_s(string, TEXT("Russian\n"));
                    }
                    else
                    {
                        lResult = SendDlgItemMessage(window, IDC_LANGUAGE_UKRAINIAN, BM_GETCHECK, 0U, 0U);
                        if (lResult == BST_CHECKED)
                        {
                            _tcscat_s(string, TEXT("Ukrainian\n"));
                        }
                    }
                }

                MessageBox(window, string, TEXT("Radio Button"), MB_OK | MB_ICONINFORMATION);
            }
            break;
        case WM_INITDIALOG:
            SendDlgItemMessage(window, IDC_COLOR_GREEN, BM_SETCHECK, static_cast<WPARAM>(BST_CHECKED), 0U);
            SendDlgItemMessage(window, IDC_LANGUAGE_ENGLISH, BM_SETCHECK, static_cast<WPARAM>(BST_CHECKED), 0U);
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}