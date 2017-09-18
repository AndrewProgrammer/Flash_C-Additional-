#include <ctime>
#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>
// Необходимо подключить этот заголовочный файл, чтобы работали общие элементы управления.
#include <CommCtrl.h>

// Необходимо подключить эту библиотеку, чтобы работали общие элементы управления.
#pragma comment(lib, "comctl32")

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_dialog = nullptr;
HWND g_progress1 = nullptr;
HWND g_progress2 = nullptr;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnClose(HWND window);
VOID OnCommand(HWND window, INT id, HWND control, UINT codeNotify);
BOOL OnInitDialog(HWND window, HWND focus, LPARAM lParam);
VOID OnTimer(HWND window, UINT id);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
{
    return DialogBox(instance, MAKEINTRESOURCE(IDD_DIALOG), nullptr, DialogProcedure); 
}

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        HANDLE_MSG(window, WM_CLOSE, OnClose);
        HANDLE_MSG(window, WM_COMMAND, OnCommand);
        HANDLE_MSG(window, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(window, WM_TIMER, OnTimer);
    }

    return FALSE;
}

VOID OnClose(HWND window)
{
    EndDialog(window, 0);
}

VOID OnCommand(HWND window, INT id, HWND /*control*/, UINT /*codeNotify*/)
{
    if (id == IDC_START)
    {
        SetTimer(window, 1U, 100U, nullptr);
    }
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/)
{
    srand(static_cast<UINT>(time(nullptr)));

    g_dialog = window;
    g_progress1 = GetDlgItem(g_dialog, IDC_PROGRESS1);
    g_progress2 = GetDlgItem(g_dialog, IDC_PROGRESS2);

    // Установка интервала для индикатора.
    SendMessage(g_progress1, PBM_SETRANGE, 0U, MAKELPARAM(0, 60));

    // Установка шага приращения  индикатора.
    SendMessage(g_progress1, PBM_SETSTEP, 1U, 0U);

    // Установка текущей позиции индикатора.
    SendMessage(g_progress1, PBM_SETPOS, 0U, 0U);

    // Установка цвета фона индикатора.
    // Это сообщение сработает только при отключенных визуальных стилях.
    SendMessage(g_progress1, PBM_SETBKCOLOR, 0U, static_cast<LPARAM>(RGB(0, 0, 255)));

    // Установка цвета заполняемых прямоугольников.
    // Это сообщение сработает только при отключенных визуальных стилях.
    SendMessage(g_progress1, PBM_SETBARCOLOR, 0U, static_cast<LPARAM>(RGB(255, 255, 0)));

    SendMessage(g_progress2, PBM_SETRANGE, 0U, MAKELPARAM(0, 60));
    SendMessage(g_progress2, PBM_SETSTEP, 1U, 0U);
    SendMessage(g_progress2, PBM_SETPOS, 0U, 0U);
    SendMessage(g_progress2, PBM_SETBKCOLOR, 0U, static_cast<LPARAM>(RGB(0, 255, 0)));
    SendMessage(g_progress2, PBM_SETBARCOLOR, 0U, static_cast<LPARAM>(RGB(255, 0, 255))); 

    return TRUE;
}

VOID OnTimer(HWND /*window*/, UINT /*id*/)
{
    // Изменение текущей позиции индикатора путем прибавления шага.
    SendMessage(g_progress1, PBM_STEPIT, 0U, 0U);

    INT position = rand() % 60;

    // Установка текущей позиции индикатора.
    SendMessage(g_progress2, PBM_SETPOS, static_cast<WPARAM>(position), 0U);
}