#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>
#include <CommCtrl.h>

#pragma comment(lib, "comctl32")

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_dialog = nullptr;
HWND g_edit = nullptr;
HWND g_spin = nullptr;
HWND g_spinBuddy = nullptr;

UINT g_count = 0U;

TCHAR g_text[100] = {};

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
        // Получение текущей позиции счетчика.
        INT time = SendMessage(g_spin, UDM_GETPOS32, 0U, 0U);

        SetTimer(window, 1U, time, nullptr);

        // Получение текста с элемента Edit Control.
        GetWindowText(g_edit, g_text, ARRAYSIZE(g_text));

        g_count = 1U;
    }
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/)
{
    g_dialog = window;
    g_spin = GetDlgItem(g_dialog, IDC_SPIN);
    g_edit = GetDlgItem(g_dialog, IDC_EDIT);
    g_spinBuddy = GetDlgItem(g_dialog, IDC_SPIN_BUDDY);

    // Установка диапазона счетчика.
    SendMessage(g_spin, UDM_SETRANGE32, 100U, 10000U);

    // Установка правила приращения.
    UDACCEL acceleration[] = {{1U, 10U}, {3U, 100U}, {5U, 500U}};
    SendMessage(g_spin, UDM_SETACCEL, ARRAYSIZE(acceleration), reinterpret_cast<LPARAM>(acceleration));

    // Установка приятеля.
    SendMessage(g_spin, UDM_SETBUDDY, reinterpret_cast<WPARAM>(g_spinBuddy), 0U);

    SetWindowText(g_spinBuddy, TEXT("100"));
    SetWindowText(g_edit, TEXT("Common Control - Spin Control"));

    return TRUE;
}

VOID OnTimer(HWND window, UINT /*id*/)
{
    // Проверка, выведен ли весь текст.
    if (g_count <= _tcslen(g_text))
    {
        TCHAR* textCopy = new TCHAR[ARRAYSIZE(g_text)];
        ZeroMemory(textCopy, ARRAYSIZE(g_text));

        // Добавление к заголовку одного символа.
        _tcsncpy_s(textCopy, ARRAYSIZE(g_text), g_text, g_count++);

        // Вывод текста в заголовок главного окна.
        SetWindowText(window, textCopy);

        delete [] textCopy;
    }
    else 
    {
        // Удаление таймера.
        KillTimer(window, 1U);
    }
}