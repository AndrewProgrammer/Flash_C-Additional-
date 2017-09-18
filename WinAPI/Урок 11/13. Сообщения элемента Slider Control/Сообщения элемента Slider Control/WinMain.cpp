#include <ctime>
#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>
#include <CommCtrl.h>

#pragma comment(lib, "comctl32")

#include "resource.h"

#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

HWND g_dialog = nullptr;
HWND g_horizontalSlider = nullptr;
HWND g_verticalSlider = nullptr;

INT g_max = 400;
INT g_min = 0;

BOOL CALLBACK DialogProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
VOID OnClose(HWND window);
VOID OnHScroll(HWND window, HWND control, UINT code, INT position);
BOOL OnInitDialog(HWND window, HWND focus, LPARAM lParam);
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
        HANDLE_MSG(window, WM_HSCROLL, OnHScroll);
        HANDLE_MSG(window, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(window, WM_VSCROLL, OnVScroll);
    }

    return FALSE;
}

VOID OnClose(HWND window)
{
    EndDialog(window, 0);
}

VOID OnHScroll(HWND window, HWND control, UINT code, INT /*position*/)
{
    static INT oldPosition = 0;

    INT currrentPosition = SendMessage(control, TBM_GETPOS, 0U, 0U);
    RECT windowRectangle = {};

    GetWindowRect(window, &windowRectangle);

    switch (code)
    {
        case TB_BOTTOM:
            // Нажата клавиша "End" (VK_END) - ползунок устанавливается в крайнее правое положение.
            windowRectangle.right += g_max - oldPosition;
            break;
        case TB_TOP:
            // Нажата клавиша "Home" (VK_HOME) - ползунок устанавливается в крайнее левое положение.
            windowRectangle.right -= oldPosition - g_min;
            break;
        case TB_LINEUP: 
            // Нажата клавиша "стрелка влево" (VK_LEFT).
            if (currrentPosition > g_min)
            {
                --windowRectangle.right;
            }
            break;
        case TB_LINEDOWN:
            // Нажата клавиша "стрелка вправо" (VK_RIGHT).
            if (currrentPosition < g_max)
            {
                ++windowRectangle.right;
            }
            break;
        case TB_PAGEDOWN:
        case TB_PAGEUP:
        case TB_THUMBPOSITION:
            // Отпущена кнопка мыши после перемещения ползунка.
        case TB_THUMBTRACK:
            // Ползунок перемещается с помощью мыши.
            windowRectangle.right += currrentPosition - oldPosition;
            break;
    }

    oldPosition = currrentPosition;
    
    MoveWindow(
        window,
        windowRectangle.left,
        windowRectangle.top,
        windowRectangle.right - windowRectangle.left,
        windowRectangle.bottom - windowRectangle.top,
        TRUE
    );
}

BOOL OnInitDialog(HWND window, HWND /*focus*/, LPARAM /*lParam*/)
{
    g_dialog = window;
    g_horizontalSlider = GetDlgItem(g_dialog, IDC_SLIDER1);
    g_verticalSlider = GetDlgItem(g_dialog, IDC_SLIDER2);
    
    SendMessage(g_horizontalSlider, TBM_SETRANGE, TRUE, MAKELPARAM(g_min, g_max));
    SendMessage(g_verticalSlider, TBM_SETRANGE, TRUE, MAKELPARAM(g_min, g_max));

    return TRUE;
}

VOID OnVScroll(HWND window, HWND control, UINT code, INT /*position*/)
{
    static INT oldPosition = 0;

    INT currrentPosition = SendMessage(control, TBM_GETPOS, 0U, 0U);
    RECT windowRectangle = {};

    GetWindowRect(window, &windowRectangle);

    switch (code)
    {
        case TB_BOTTOM:
            // Нажата клавиша "End" (VK_END) - ползунок устанавливается в крайнее нижнее положение.
            windowRectangle.bottom += g_max - oldPosition;
            break;
        case TB_TOP:
            // Нажата клавиша "Home" (VK_HOME) - ползунок устанавливается в крайнее верхнее 
            // положение.
            windowRectangle.bottom -= oldPosition - g_min;
            break;
        case TB_LINEUP: 
            // Нажата клавиша "стрелка вверх" (VK_UP).
            if (currrentPosition > g_min)
            {
                --windowRectangle.bottom;
            }
            break;
        case TB_LINEDOWN:
            // Нажата клавиша "стрелка вниз" (VK_DOWN).
            if (currrentPosition < g_max)
            {
                ++windowRectangle.bottom;
            }
            break;
        case TB_PAGEDOWN:
        case TB_PAGEUP:
        case TB_THUMBPOSITION:
            // Отпущена кнопка мыши после перемещения ползунка.
        case TB_THUMBTRACK:
            // Ползунок перемещается с помощью мыши.
            windowRectangle.bottom += currrentPosition - oldPosition;
            break;
    }

    oldPosition = currrentPosition;

    MoveWindow(
        window,
        windowRectangle.left,
        windowRectangle.top,
        windowRectangle.right - windowRectangle.left,
        windowRectangle.bottom - windowRectangle.top,
        TRUE
    );
}