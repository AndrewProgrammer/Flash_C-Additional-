#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

VOID AddKeyboardMessageInfo(TCHAR key, WORD wepeat);
VOID AddKeyboardKeyMessageInfo(LPCTSTR message, UINT keyCode, WORD repeat);
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT showCommand)
{
    TCHAR className[] = TEXT("Win32Application");

    WNDCLASSEX windowClass = {};
    windowClass.cbClsExtra = 0;
    windowClass.cbSize = sizeof(windowClass);
    windowClass.cbWndExtra = 0;
    windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    windowClass.hInstance = instance;
    windowClass.lpfnWndProc = WindowProcedure;
    windowClass.lpszClassName = className;
    windowClass.lpszMenuName = nullptr;
    windowClass.style = CS_HREDRAW | CS_VREDRAW;

    INT exitCode = 0;

    if (RegisterClassEx(&windowClass))
    {
        HWND window = CreateWindowEx(0UL, className, TEXT("Keyboard Messages"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance, nullptr);

        ShowWindow(window, showCommand);
        UpdateWindow(window);

        MSG message = {};

        while (GetMessage(&message, nullptr, 0U, 0U))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        exitCode = message.wParam;
    }

    return exitCode;
}

VOID AddKeyboardMessageInfo(TCHAR key, WORD repeat)
{
    FILE* file = nullptr;

    if (_tfopen_s(&file, TEXT("Messages.txt"), TEXT("a")) == 0)
    {
        TCHAR line[100] = {};

        _stprintf_s(line, TEXT("Message: WM_CHAR, Key: %c, Key code: %d, Repeat: %d\r\n"), key, key, repeat);
        _fputts(line, file);

        fclose(file);
    }
}

VOID AddKeyboardKeyMessageInfo(LPCTSTR message, UINT keyCode, WORD repeat)
{
    FILE* file = nullptr;

    if (_tfopen_s(&file, TEXT("Messages.txt"), TEXT("a")) == 0)
    {
        TCHAR line[100] = {};

        _stprintf_s(line, TEXT("Message: %s, Key code: %d, Repeat: %d\r\n"), message, keyCode, repeat);
        _fputts(line, file);

        fclose(file);
    }
}

LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_CHAR:
            AddKeyboardMessageInfo(static_cast<TCHAR>(wParam), LOWORD(lParam));
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
            AddKeyboardKeyMessageInfo(TEXT("WM_KEYDOWN"), wParam, LOWORD(lParam));
            break;
        case WM_KEYUP:
            AddKeyboardKeyMessageInfo(TEXT("WM_KEYUP"), wParam, LOWORD(lParam));
            break;
        default:
            result = DefWindowProc(window, message, wParam, lParam);
            break;
    }

    return result;
}