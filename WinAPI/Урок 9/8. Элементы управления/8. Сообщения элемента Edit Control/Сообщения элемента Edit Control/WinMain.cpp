#include <tchar.h>
#include <Windows.h>

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' \
publicKeyToken='6595b64144ccf1df' language='*'\"")

#define WM_POSITION WM_APP //Это то что мы выводим выше нашего окна

HWND g_copy = nullptr;
HWND g_cut = nullptr;
HWND g_delete = nullptr;
HWND g_edit = nullptr;
HWND g_paste = nullptr;
HWND g_selectAll = nullptr;
HWND g_undo = nullptr;

WNDPROC g_originalProcedure = nullptr;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK EditProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID EnableDisableButton();
VOID GetPosition();

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*show*/)
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
            switch (LOWORD(wParam))
            {
                case IDC_COPY: 
                    // Копирование выделенного фрагмента текста.
                    SendMessage(g_edit, WM_COPY, 0U, 0U);
                    break;
                case IDC_CUT: 
                    // Вырезание выделенного фрагмент текста.
                    SendMessage(g_edit, WM_CUT, 0U, 0U);

                    // Определение текущих координат курсора.
                    SendMessage(g_edit, WM_POSITION, 0U, 0U);
                    break;
                case IDC_DELETE: 
                    // Удаление выделенного фрагмент текста.
                    SendMessage(g_edit, WM_CLEAR, 0U, 0U);

                    // Определение текущих координат курсора.
                    SendMessage(g_edit, WM_POSITION, 0U, 0U);
                    break;
                case IDC_PASTE: 
                    // Вставка текста в Edit Control из буфера обмена.
                    SendMessage(g_edit, WM_PASTE, 0U, 0U);

                    // Определение текущих координат курсора.
                    SendMessage(g_edit, WM_POSITION, 0U, 0U);
                    break;
                case IDC_SELECT_ALL:
                    // Выделение всего текста в Edit Control.
                    SendMessage(g_edit, EM_SETSEL, 0U, -1);

                    // Определение текущих координат курсора.
                    SendMessage(g_edit, WM_POSITION, 0U, 0U);
                    break;
                case IDC_UNDO: 
                    // Отмена последнего действия.
                    SendMessage(g_edit, WM_UNDO, 0U, 0U);

                    // Определение текущих координат курсора.
                    SendMessage(g_edit, WM_POSITION, 0U, 0U);
                    break;
            }
            break;
        case WM_INITDIALOG:
            g_edit = GetDlgItem(window, IDC_EDIT);
            g_copy = GetDlgItem(window, IDC_COPY);
            g_cut = GetDlgItem(window, IDC_CUT);
            g_paste = GetDlgItem(window, IDC_PASTE);
            g_delete = GetDlgItem(window, IDC_DELETE);
            g_selectAll = GetDlgItem(window, IDC_SELECT_ALL);
            g_undo = GetDlgItem(window, IDC_UNDO);

            // Переопределение оконной процедуры текстового поля.
            g_originalProcedure = reinterpret_cast<WNDPROC>(
                SetWindowLong(g_edit, GWL_WNDPROC, reinterpret_cast<LONG>(EditProcedure))
            );

            // Отправка пользовательского сообщения для определения текущих координат курсора.
            SendMessage(g_edit, WM_POSITION, 0U, 0U);
            break;
        default:
            result = FALSE;
            break;
    }

    return result;
}

LRESULT CALLBACK EditProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message == WM_POSITION ||
        message == WM_LBUTTONDOWN ||
        message == WM_LBUTTONUP ||
        message == WM_KEYDOWN ||
        message == WM_KEYUP ||
        message == WM_MOUSEMOVE && (wParam & MK_LBUTTON))
    {
        EnableDisableButton();
        GetPosition();
    }

    // Вызов стандартного обработчика сообщений.
    return CallWindowProc(g_originalProcedure, window, message, wParam, lParam);
}

VOID EnableDisableButton()
{
    // Получение границ выделенного текста.
    DWORD position = SendMessage(g_edit, EM_GETSEL, 0U, 0U);

    WORD beginPosition = LOWORD(position);
    WORD endPosition = HIWORD(position);

    // Если текст выделен.
    if (endPosition != beginPosition)
    {
        EnableWindow(g_copy, TRUE);
        EnableWindow(g_cut, TRUE);
        EnableWindow(g_delete, TRUE);
    }
    else
    {
        EnableWindow(g_copy, FALSE);
        EnableWindow(g_cut, FALSE);
        EnableWindow(g_delete, FALSE);
    }

    // Если в буфере имеется текст.
    if (IsClipboardFormatAvailable(CF_TEXT))
    {
        EnableWindow(g_paste, TRUE);
    }
    else
    {
        EnableWindow(g_paste, FALSE);
    }

    // Если существует возможность отмены последнего действия.
    if (SendMessage(g_edit, EM_CANUNDO, 0U, 0U))
    {
        EnableWindow(g_undo, TRUE);
    }
    else
    {
        EnableWindow(g_undo, FALSE);
    }

    // Определение длины текста в Edit Control.
    INT length = SendMessage(g_edit, WM_GETTEXTLENGTH, 0U, 0U);

    // Если выделен весь текст в Edit Control.
    if (length != endPosition - beginPosition)
    {
        EnableWindow(g_selectAll, TRUE);
    }
    else
    {
        EnableWindow(g_selectAll, FALSE);
    }
}

VOID GetPosition()
{
    // Получение номера строки, в которой расположен курсор.
    INT row = SendMessage(g_edit, EM_LINEFROMCHAR, static_cast<WPARAM>(-1), 0U);

    DWORD start = 0UL;
    DWORD end = 0UL;

    // Получение границ выделения текста.
    SendMessage(g_edit, EM_GETSEL, reinterpret_cast<WPARAM>(&start), reinterpret_cast<LPARAM>(&end));

    // Получение номера первого символа указанной строки.
    INT column = start - SendMessage(g_edit, EM_LINEINDEX, row, 0U);

    // Получение дескриптора родительского окна (диалога).
    HWND parent = GetParent(g_edit);
    TCHAR buffer[50] = {};

    _stprintf_s(buffer, TEXT("Row %d, Column %d"), row + 1, column + 1); 

    // Установка в заголовок главного окна текущих координат курсора.
    SetWindowText(parent, buffer);

    // Перевод фокуса ввода на Edit Control.
    SetFocus(g_edit);
}