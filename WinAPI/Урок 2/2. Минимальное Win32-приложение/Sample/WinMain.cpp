#include <tchar.h>
// Библиотека Windows.h содержит определения, макросы и структуры, которые используются при написании приложений под Windows.
#include <Windows.h>

// Прототип оконной процедуры.
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(
    HINSTANCE instance, // Дескриптор экземпляра приложения.
    HINSTANCE /*previousInstance*/, // Всегда равен 0 и необходим для совместимости.
    LPTSTR /*commandLine*/, // Параметры командной строки (без имени исполняемого файла).
    INT showCommand // Способ визуализации окна при запуске программы.
)
{
    // 1. Определение класса окна.

    // Имя класса окна.
    TCHAR className[] = TEXT("MinimalWin32Application");

    WNDCLASSEX windowClass = {};
    windowClass.cbClsExtra = 0; // Используется Windows.
    windowClass.cbSize = sizeof(windowClass); // Размер структуры WNDCLASSEX.
    windowClass.cbWndExtra = 0; // Используется Windows.
    windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // Заполнение окна белым цветом.
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW); // Загрузка стандартного курсора.
    windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION); // Загрузка стандатной иконки.
    windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION); // Загрузка стандатной иконки.
    windowClass.hInstance = instance; // Дескриптор данного приложения.
    windowClass.lpfnWndProc = WindowProcedure; // Адрес оконной процедуры.
    windowClass.lpszClassName = className; // Имя класса окна.
    windowClass.lpszMenuName = nullptr; // Приложение не содержит меню.
    windowClass.style = CS_HREDRAW | CS_VREDRAW; // CS (Class Style) - стиль класса окна.

    // Стили класса окна:
    // CS_HREDRAW - Перерисовать все окно, если изменен размер по горизонтали.
    // CS_VREDRAW - Перерисовать все окно, если изменен размер по вертикали.

    INT exitCode = 0;

    // 2. Регистрация класса окна.

    if (RegisterClassEx(&windowClass))
    {
        // 3. Создание окна.

        // Создается окно и переменной window присваивается дескриптор окна.
        HWND window = CreateWindowEx(
            0UL, // Расширенный стиль окна.
            className, // Имя класса окна.
            TEXT("Minimal Win32 Application"), // Заголовок окна.
            WS_OVERLAPPEDWINDOW, // Стиль окна.
            CW_USEDEFAULT, // X-координата верхнего левого угла.
            CW_USEDEFAULT, // Y-координата верхнего левого угла.
            CW_USEDEFAULT, // Ширина окна.
            CW_USEDEFAULT, // Высота окна.
            nullptr, // Дескриптор родительского окна.
            nullptr, // Дескриптор меню окна.
            instance, // Дескриптор приложения, создавшего окно.
            nullptr // Указатель на область данных приложения.
        );

        // Стили окна:
        // WS_MINIMIZE - Создает первоначально минимизированное окно.
        // WS_MAXIMIZE - Создает первоначально максимизированное окно.
        // WS_BORDER - Создает окно с тонкой границей.
        // WS_CAPTION - Создает окно, у которого имеется заголовок (уже включает в себя стиль WS_BORDER).
        // WS_SYSMENU - Создает окно, у которого имеется оконное меню в заголовке (используется совместно со стилем WS_CAPTION).
        // WS_MAXIMIZEBOX - Создает окно, у которого имеется кнопка "Развернуть" в заголовке (используется совместно со стилем WS_SYSMENU).
        // WS_MINIMIZEBOX - Создает окно, у которого имеется кнопка "Свернуть" в заголовке (используется совместно со стилем WS_SYSMENU).
        // WS_THICKFRAME - Создает окно, у которого имеется изменяемая граница.
        // WS_OVERLAPPED - Создает перекрывающее окно (у перекрывающего окна имеется граница и заголовок).
        // WS_OVERLAPPEDWINDOW - Создает перекрывающее окно, включает в себя стили WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MAXIMIZEBOX, WS_MINIMIZEBOX.

        // 4. Отображение окна.

        ShowWindow(window, showCommand);
        UpdateWindow(window); // Перерисовка окна.

        // 5. Запуск цикла обработки сообщений.

        MSG message = {};

        // Получение очередного сообщения из очереди сообщений.
        // Функция GetMessage возвращает значение отличное от ноля до тех пор, пока не получит сообщение WM_QUIT.
        while (GetMessage(&message, nullptr, 0U, 0U))
        {
            // Трансляция сообщения.
            TranslateMessage(&message);

            // Диспетчеризация сообщения.
            DispatchMessage(&message);
        }

        // Присваивание значения, которое было передано в функцию PostQuitMessage.
        exitCode = message.wParam;
    }

    return exitCode;
}

LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_DESTROY: // Сообщение о завершении программы.
            PostQuitMessage(0); // Отправка сообщения WM_QUIT.
            break;
        default:
            // Все сообщения, которые не обрабатываются в данной оконной функции направляются обратно Windows для обработки по умолчанию.
            result = DefWindowProc(window, message, wParam, lParam);
            break;
    }

    return result;
}