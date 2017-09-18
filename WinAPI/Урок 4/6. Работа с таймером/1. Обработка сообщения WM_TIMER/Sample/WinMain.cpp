#include <ctime>
#include <tchar.h>
#include <Windows.h>

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
        HWND window = CreateWindowEx(0UL, className, TEXT("Win32 Application"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance, nullptr);

        ShowWindow(window, showCommand);
        UpdateWindow(window);

        MessageBox(nullptr, TEXT("To start timer press ENTER, to stop press ESC"), TEXT("Timer"), MB_OK | MB_ICONINFORMATION);

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

LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_KEYDOWN:
            {
                switch (wParam)
                {
                    case VK_RETURN:
                        // Установка таймера по нажатию клавиши Enter.
                        SetTimer(
                            window, // Дескриптор окна.
                            1U, // Идентификатор устанавливаемого таймера.
                            1000U, // Временной интервал для таймера в миллисекундах.
                            nullptr // Указатель на функцию-обработчик прерываний таймера.
                        );
                        break;
                    case VK_ESCAPE:
                        // Уничтожение таймера по нажатию клавиши Escape.
                        KillTimer(
                            window, // Дескриптор окна.
                            1U // Идентификатор установленного таймера.
                        );
                        break;
                }
            }
            break;
        case WM_TIMER:
            // wParam - идентификатор таймера.
            // lParam - указатель на функцию-обработчик прерываний таймера.
            {
                TCHAR caption[100] = {};

                // Количество секунд, прошедших с 01.01.1970.
                time_t currentTime = time(nullptr);

                // Формирование строки даты согласно установок системы.
                _tcscpy_s(caption, _tctime(&currentTime));

                caption[_tcslen(caption) - 1U] = TEXT('\0');

                // Вывод даты и времени в заголовок окна.
                SetWindowText(window, caption);
            }
            break;
        default:
            result = DefWindowProc(window, message, wParam, lParam);
            break;
    }

    return result;
}