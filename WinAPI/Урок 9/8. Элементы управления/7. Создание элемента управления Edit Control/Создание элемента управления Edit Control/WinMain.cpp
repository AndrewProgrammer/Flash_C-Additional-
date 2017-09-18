#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure); 
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM /*wParam*/, LPARAM lParam)
{
    BOOL result = TRUE;

    static HWND button = nullptr;
    static HWND editDestination = nullptr;
    static HWND editSource = nullptr;

    switch (message)
    {
        case WM_CLOSE:
            EndDialog(window, 0);
            break;
        case WM_COMMAND:
            if (button == reinterpret_cast<HWND>(lParam))
            {
                INT length = SendMessage(editSource, WM_GETTEXTLENGTH, 0U, 0U);
                TCHAR* buffer = new TCHAR[length + 1];

                memset(buffer, 0, (length + 1) * sizeof(TCHAR));

                GetWindowText(editSource, buffer, length + 1);
                SetWindowText(editDestination, buffer);

                delete [] buffer;
            }
            break;
        case WM_INITDIALOG:
            {
                HINSTANCE instance = GetModuleHandle(nullptr);

                editSource = CreateWindowEx(
                    0UL,
                    TEXT("EDIT"),
                    nullptr,
                    ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN | WS_BORDER | WS_CHILD | WS_TABSTOP | WS_VISIBLE | 
                        WS_VSCROLL,
                    10,
                    7,
                    150,
                    100,
                    window,
                    nullptr,
                    instance,
                    nullptr
                );
                editDestination = CreateWindowEx(
                    0UL,
                    TEXT("EDIT"),
                    nullptr,
                    ES_AUTOVSCROLL | ES_MULTILINE | ES_READONLY | ES_WANTRETURN | WS_BORDER | WS_CHILD | WS_VISIBLE | 
                        WS_VSCROLL,
                    170,
                    7,
                    150,
                    100,
                    window,
                    nullptr,
                    instance,
                    nullptr
                );
                button = CreateWindowEx(
                    0UL,
                    TEXT("BUTTON"),
                    TEXT("Click Me"),
                    WS_CHILD | WS_TABSTOP | WS_VISIBLE,
                    10,
                    110,
                    310,
                    40,
                    window,
                    nullptr,
                    instance,
                    nullptr
                );
            }
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}