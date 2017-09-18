#include <tchar.h>
#include <Windows.h>

// Настройка визуального оформления элементов управления согласно настройкам пользователя.
#pragma comment(linker, "\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

INT WINAPI _tWinMain(HINSTANCE /*instance*/, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT /*showCommand*/)
{
    MessageBox(nullptr, TEXT("This is the message box sample."), TEXT("Message Box"), MB_OK | MB_ICONINFORMATION);

    INT result = MessageBox(nullptr, TEXT("Press a button."), TEXT("Message Box"), MB_YESNO | MB_ICONINFORMATION);

    switch (result)
    {
        case IDNO:
            MessageBox(nullptr, TEXT("You pressed NO."), TEXT("Message Box"), MB_OK | MB_ICONINFORMATION);
            break;
        case IDYES:
            MessageBox(nullptr, TEXT("You pressed YES."), TEXT("Message Box"), MB_OK | MB_ICONINFORMATION);
            break;
    }

    return 0;
}