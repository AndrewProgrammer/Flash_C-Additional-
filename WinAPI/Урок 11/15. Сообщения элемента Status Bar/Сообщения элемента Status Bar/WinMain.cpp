#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>
#include <CommCtrl.h>

#pragma comment(lib, "comctl32")

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_dialog = nullptr;
HWND g_parameter1 = nullptr;
HWND g_parameter2 = nullptr;
HWND g_spin = nullptr;
HWND g_spinBuddy = nullptr;
HWND g_status = nullptr;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnClose(HWND window);
VOID OnCommand(HWND window, INT id, HWND control, UINT codeNotify);
BOOL OnInitDialog(HWND window, HWND focus, LPARAM lParam);
VOID OnSize(HWND window, UINT state, INT width, INT height);
VOID OnVScroll(HWND window, HWND control, UINT code, INT position);

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
        HANDLE_MSG(window, WM_SIZE, OnSize);
        HANDLE_MSG(window, WM_VSCROLL, OnVScroll);
    }

    return FALSE;
}

VOID OnClose(HWND window)
{
    EndDialog(window, 0);
}

VOID OnCommand(HWND /*window*/, INT id, HWND /*control*/, UINT /*codeNotify*/)
{
    // Отображение статуса флажков в строке состояния.
    switch (id)
    {
        case IDC_PARAMETER1:
            {
                LRESULT lResult = SendMessage(g_parameter1, BM_GETCHECK, 0U, 0U);

                if (lResult == BST_CHECKED)
                {
                    SendMessage(g_status, SB_SETTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: On")));
                    SendMessage(g_status, SB_SETTIPTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: On")));
                }
                else
                {
                    SendMessage(g_status, SB_SETTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: Off")));
                    SendMessage(g_status, SB_SETTIPTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: Off")));
                }
            }
            break;
        case IDC_PARAMETER2:
            {
                LRESULT lResult = SendMessage(g_parameter2, BM_GETCHECK, 0U, 0U);

                if (lResult == BST_CHECKED)
                {
                    SendMessage(g_status, SB_SETTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: On")));
                    SendMessage(g_status, SB_SETTIPTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: On")));
                }
                else
                {
                    SendMessage(g_status, SB_SETTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: Off")));
                    SendMessage(g_status, SB_SETTIPTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: Off")));
                }
            }
            break;
    }
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/)
{
    g_dialog = window;
    g_parameter1 = GetDlgItem(g_dialog, IDC_PARAMETER1);
    g_parameter2 = GetDlgItem(g_dialog, IDC_PARAMETER2);
    g_spin = GetDlgItem(g_dialog, IDC_SPIN);
    g_spinBuddy = GetDlgItem(g_dialog, IDC_SPIN_BUDDY);

    // Установка диапазона счетчика.
    SendMessage(g_spin, UDM_SETRANGE32, 0U, 100U);

    // Установка приятеля для счетчика.
    SendMessage(g_spin, UDM_SETBUDDY, reinterpret_cast<WPARAM>(g_spinBuddy), 0U);
    SetWindowText(g_spinBuddy, TEXT("0"));

    // Создание строки состояния.
    g_status = CreateStatusWindow(
        WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS | SBARS_SIZEGRIP,
        nullptr,
        g_dialog,
        WM_USER
    );

    // Разделение строки состояния на отдельные секции.
    INT parts[] = {40, 110, 220, -1};

    SendMessage(g_status, SB_SETPARTS, ARRAYSIZE(parts), reinterpret_cast<LPARAM>(parts));

    // Установка текста и всплывающей подсказки для каждой секции.
    SendMessage(g_status, SB_SETTEXT, 1U, reinterpret_cast<LPARAM>(TEXT("Counter: 0")));
    SendMessage(g_status, SB_SETTIPTEXT, 1U, reinterpret_cast<LPARAM>(TEXT("Counter: 0")));
    SendMessage(g_status, SB_SETTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: Off")));
    SendMessage(g_status, SB_SETTIPTEXT, 2U, reinterpret_cast<LPARAM>(TEXT("Parameter 1: Off")));
    SendMessage(g_status, SB_SETTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: Off")));
    SendMessage(g_status, SB_SETTIPTEXT, 3U, reinterpret_cast<LPARAM>(TEXT("Parameter 2: Off")));

    // Загрузка иконки из ресурсов.
    HICON icon = LoadIcon(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDI_CARTMAN));

    // Установка иконки в первую секцию строки состояния.
    SendMessage(g_status, SB_SETICON, 0U, reinterpret_cast<LPARAM>(icon));

    // Установка цвета фона строки состояния.
    SendMessage(g_status, SB_SETBKCOLOR, 0U, static_cast<LPARAM>(RGB(255, 200, 255)));

    return TRUE;
}

VOID OnSize(HWND /*window*/, UINT /*state*/, INT /*width*/, INT /*height*/)
{
    // Установка размера строки состояния, равного ширине клиентской области главного окна.
    SendMessage(g_status, WM_SIZE, 0U, 0U);
}

VOID OnVScroll(HWND /*window*/, HWND /*control*/, UINT /*code*/, INT position)
{
    // Обработчик сообщения нажатия на одну из стрелок счетчика.
    TCHAR buffer[30] = {};

    _stprintf_s(buffer, TEXT("Counter: %d"), position);

    // Отображение состояния счетчика в строке состояния.
    SendMessage(g_status, SB_SETTEXT, 1U, reinterpret_cast<LPARAM>(buffer));
    SendMessage(g_status, SB_SETTIPTEXT, 1U, reinterpret_cast<LPARAM>(buffer));
}