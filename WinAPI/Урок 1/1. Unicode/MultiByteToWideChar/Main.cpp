#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    char ansiString[] = "MultiByteToWideChar converts ANSI string to Unicode string";

    int capacity = MultiByteToWideChar(CP_ACP, 0U, ansiString, -1, nullptr, 0);
    int length = capacity - 1;

    wchar_t* unicodeString = new wchar_t[capacity];

    MultiByteToWideChar(CP_ACP, 0U, ansiString, -1, unicodeString, capacity);

    cout << "ANSI string:" << endl;
    cout << "\tLength: " << length << " characters" << endl;
    cout << "\tSize: " << sizeof(ansiString) << " bytes" << endl;

    cout << endl;
    cout << "Unicode string:" << endl;
    cout << "\tLength: " << wcslen(unicodeString) << " characters" << endl;
    cout << "\tSize: " << capacity * sizeof(unicodeString[0]) << " bytes" << endl;

    delete[] unicodeString;

    return 0;
}