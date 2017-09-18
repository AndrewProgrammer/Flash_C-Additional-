#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_editAdd = nullptr;
HWND g_editSearch = nullptr;
HWND g_list1 = nullptr;
HWND g_list2 = nullptr;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnClose(HWND window);
VOID OnCommand(HWND window, INT id, HWND control, UINT codeNotify);
BOOL OnInitDialog(HWND window, HWND focus, LPARAM lParam);

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

VOID OnCommand(HWND window, INT id, HWND /*control*/, UINT codeNotify)
{
    switch (id)
    {
        case IDC_BUTTON_ADD: 
            {
                // Определение длины текста, введенного в текстовое поле.
                UINT length = SendMessage(g_editAdd, WM_GETTEXTLENGTH, 0U, 0U);

                // Выделение памяти необходимого размера.
                TCHAR* buffer = new TCHAR[length + 1U];

                // Копирование текста, введенного в текстовое поле в выделенную память.
                GetWindowText(g_editAdd, buffer, length + 1U);

                if (_tcslen(buffer) > 0U)
                {
                    // Проверка, имеется ли уже в списке введенный текст. 
                    INT index = SendMessage(
                        g_list1,
                        LB_FINDSTRINGEXACT,
                        static_cast<WPARAM>(-1),
                        reinterpret_cast<LPARAM>(buffer)
                    );

                    if (index == LB_ERR)
                    {
                        // Добавление текста в список.
                        SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(buffer));
                    }
                    else
                    {
                        MessageBox(window, TEXT("Such person already exists"), TEXT("Add Person"), MB_OK | MB_ICONSTOP);
                    }
                }

                delete [] buffer;
            }
            break;
        case IDC_BUTTON_DELETE:
            {
                // Получение индекса выбранного элемента списка.
                INT index = SendMessage(g_list1, LB_GETCURSEL, 0U, 0U);

                // Если элемент выбран.
                if (index != LB_ERR)
                {
                    // Определение длины выбранного элемента.
                    INT length = SendMessage(g_list1, LB_GETTEXTLEN, index, 0U);

                    // Выделение памяти необходимого размера.
                    TCHAR* buffer = new TCHAR[length + 1];

                    // Копирование выбранного элемента в выделенную память.
                    SendMessage(g_list1, LB_GETTEXT, index, reinterpret_cast<LPARAM>(buffer));

                    MessageBox(window, buffer, TEXT("Delete Person"), MB_OK | MB_ICONINFORMATION);

                    // Удаление строки из списка.
                    SendMessage(g_list1, LB_DELETESTRING, index, 0U);

                    delete [] buffer;
                }
                else
                {
                    MessageBox(window, TEXT("Person is not selected"), TEXT("Delete Person"), MB_OK | MB_ICONSTOP);
                }
            }
            break;
        case IDC_BUTTON_SEARCH:
            {
                // Определение длины искомого названия, введенного в текстовое поле.
                INT length = SendMessage(g_editSearch, WM_GETTEXTLENGTH, 0U, 0U);

                // Выделение памяти необходимого размера.
                TCHAR* buffer = new TCHAR[length + 1];

                // Копирование текста, введенного в текстовое поле в выделенную память.
                GetWindowText(g_editSearch, buffer, length + 1);

                if (_tcslen(buffer) > 0U)
                {
                    // Проверка, имеется ли в списке введенный текст. 
                    INT index = SendMessage(
                        g_list1,
                        LB_SELECTSTRING,
                        static_cast<WPARAM>(-1),
                        reinterpret_cast<LPARAM>(buffer)
                    );

                    if (index == LB_ERR)
                    {
                        MessageBox(window, TEXT("Person is not found"), TEXT("Search Person"), MB_OK | MB_ICONSTOP);
                    }
                }

                delete [] buffer;
            }
            break;
        case IDC_BUTTON_CLEAR:
            // Очистка содержимого списка.
            SendMessage(g_list1, LB_RESETCONTENT, 0U, 0U);
            break;
        case IDC_BUTTON_GET_SELECTED:
            {
                // Определение количества выбранных элементов в списке с множественным выбором.
                INT count = SendMessage(g_list2, LB_GETSELCOUNT, 0U, 0U);

                // Выделение памяти необходимого размера для хранения индексов выбранных элементов 
                // списка.
                INT* indices = new INT[count];

                // Заполнение динамического массива индексами выделенных элементов списка.
                SendMessage(g_list2, LB_GETSELITEMS, count, reinterpret_cast<LPARAM>(indices));

                for (INT i = 0; i < count; ++i)
                {
                    // Определение размера текста элемента списка.
                    INT length = SendMessage(g_list2, LB_GETTEXTLEN, indices[i], 0U);

                    // Выделение памяти необходимого размера.
                    TCHAR* buffer = new TCHAR[length + 1];

                    // Копирование выбранного элемента в выделенную память.
                    SendMessage(g_list2, LB_GETTEXT, indices[i], reinterpret_cast<LPARAM>(buffer));

                    MessageBox(window, buffer, TEXT("Multiline Select"), MB_OK | MB_ICONINFORMATION);

                    delete [] buffer;
                }

                delete [] indices;
            }
            break;
    }

    // Если в списке с единичным выбором текущий выбор был изменен.
    if (id == IDC_LIST1 && codeNotify == LBN_SELCHANGE)
    {
        // Получение индекса выбранного элемента списка.
        INT index = SendMessage(g_list1, LB_GETCURSEL, 0U, 0U);

        // Если элемент выбран.
        if (index != LB_ERR)
        {
            // Определение длины выбранного элемента.
            INT length = SendMessage(g_list1, LB_GETTEXTLEN, index, 0U);

            // Выделение памяти необходимого размера.
            TCHAR* buffer = new TCHAR[length + 1];

            // Копирование выбранного элемента в выделенную память.
            SendMessage(g_list1, LB_GETTEXT, index, reinterpret_cast<LPARAM>(buffer));

            // Установка текста в заголовок главного окна.
            SetWindowText(window, buffer);

            delete [] buffer;
        }
    }
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/) 
{
    // Получение дескрипторов элементов управления.
    g_list1 = GetDlgItem(window, IDC_LIST1);
    g_list2 = GetDlgItem(window, IDC_LIST2);
    g_editAdd = GetDlgItem(window, IDC_EDIT_ADD);
    g_editSearch = GetDlgItem(window, IDC_EDIT_SEARCH);

    // Добавление элементов в список с единичным выбором.
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Marilyn Monroe")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Mother Teresa")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("John F. Kennedy")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Martin Luther King")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Nelson Mandela")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Winston Churchill")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Bill Gates")));
    SendMessage(g_list1, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Rosa Parks")));

    // Установка ширины колонки для списка с множественным выбором.
    SendMessage(g_list2, LB_SETCOLUMNWIDTH, 170U, 0U);

    // Добавление элементов в список с множественным выбором.
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Oscar Wilde")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Margaret Thatcher")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Muhammad Ali")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Charles de Gaulle")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("George Orwell")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Charles Darwin")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Peter Sellers")));
    SendMessage(g_list2, LB_ADDSTRING, 0U, reinterpret_cast<LPARAM>(TEXT("Paul McCartney")));

    return TRUE;
}