#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_check = nullptr;
HWND g_combo = nullptr;
HWND g_edit = nullptr;
HWND g_list = nullptr;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnClose(HWND window);
VOID OnCommand(HWND window, INT id, HWND control, UINT codeNotify);
BOOL OnInitDialog(HWND window, HWND focus, LPARAM lParam) ;

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
    }

    return FALSE;
}

VOID OnClose(HWND window)
{
    EndDialog(window, 0);
}

VOID OnCommand(HWND /*window*/, INT id, HWND /*control*/, UINT codeNotify)
{
    // Cобытие CBN_SELCHANGE выпадающего списка происходит в тот момент, когда выбирается новый элемент в списке.
    if (id == IDC_SEASONS && codeNotify == CBN_SELCHANGE)
    {
        // Очистка элемента List Box.
        SendMessage(g_list, LB_RESETCONTENT, 0U, 0U);

        // Получение индекса выбранного элемента Combo Box.
        INT index = SendMessage(g_combo, CB_GETCURSEL, 0U, 0U);

        switch (index)
        {
            case 0:
                // Добавление в List Box названия месяца и запоминание индекса добавленного элемента.
                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("December")));

                // Установка элементу списка в соответствие число, определяющее количество дней в месяце.
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("January")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("February")));
                SendMessage(g_list, LB_SETITEMDATA, index, 28U);
                break;
            case 1:
                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("March")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("April")));
                SendMessage(g_list, LB_SETITEMDATA, index, 30U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("May")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);
                break;
            case 2:
                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("June")));
                SendMessage(g_list, LB_SETITEMDATA, index, 30U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("July")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("August")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);
                break;
            case 3:
                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("September")));
                SendMessage(g_list, LB_SETITEMDATA, index, 30U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("October")));
                SendMessage(g_list, LB_SETITEMDATA, index, 31U);

                index = SendMessage(g_list, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("November")));
                SendMessage(g_list, LB_SETITEMDATA, index, 30U);
                break;
        }
    }

    // Событие LBN_SELCHANGE списка происходит в тот момент, когда выбирается новый элемент в списке.
    if (id == IDC_MONTHS && codeNotify == LBN_SELCHANGE)
    {
        // Получение индекса выбранного элемента List Box.
        INT index = SendMessage(g_list, LB_GETCURSEL, 0U, 0U);

        // Получение значения, связанного с выбранным элементом списка.
        INT day = SendMessage(g_list, LB_GETITEMDATA, index, 0U);

        TCHAR buffer[10] = {};

        // Получение текста выбранного элемента списка.
        SendMessage(g_list, LB_GETTEXT, index, reinterpret_cast<LPARAM>(buffer));

        // Если выбран февраль.
        if (_tcscmp(buffer, TEXT("February")) == 0)
        {
            // Проверка на високосный год.
            INT status = SendMessage(g_check, BM_GETCHECK, 0U, 0U);

            if (status == BST_CHECKED)
            {
                ++day;
            }
        }

        _stprintf_s(buffer, TEXT("%d"), day);

        // Установка количества дней в элемент Edit Control.
        SendMessage(g_edit, WM_SETTEXT, 0U, reinterpret_cast<LPARAM>(buffer));
    }
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/) 
{
    // Получение дескрипторов элементов управления.
    g_check = GetDlgItem(window, IDC_LEAP_YEAR);
    g_combo = GetDlgItem(window, IDC_SEASONS);
    g_edit = GetDlgItem(window, IDC_DAYS);
    g_list = GetDlgItem(window, IDC_MONTHS);

    // Добавление времен года в Combo Box.
    SendMessage(g_combo, CB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Winter")));
    SendMessage(g_combo, CB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Spring")));
    SendMessage(g_combo, CB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Summer")));
    SendMessage(g_combo, CB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Autumn")));

    return TRUE;
}