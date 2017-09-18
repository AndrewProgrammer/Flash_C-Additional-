#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    wchar_t unicodeString[] = L"WideCharToMultiByte converts ANSI string to Unicode string";

    int capacity = WideCharToMultiByte(CP_ACP, 0U, unicodeString, -1, nullptr, 0, nullptr, nullptr);
    int length = capacity - 1;

    char* ansiString = new char[capacity];

    WideCharToMultiByte(CP_ACP, 0U, unicodeString, -1, ansiString, capacity, nullptr, nullptr);

    cout << "ANSI string:" << endl;
    cout << "\tLength: " << length << " characters" << endl;
    cout << "\tSize: " << sizeof(ansiString) << " bytes" << endl;

    cout << endl;
    cout << "Unicode string:" << endl;
    cout << "\tLength: " << wcslen(unicodeString) << " characters" << endl;
    cout << "\tSize: " << capacity * sizeof(unicodeString[0]) << " bytes" << endl;

    delete[] ansiString;

    return 0;
}