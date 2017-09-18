#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    wchar_t unicodeString[] = L"wcstombs converts Unicode string to ANSI string";

    unsigned int length = wcslen(unicodeString);
    unsigned int capacity = length + 1U;

    char* ansiString = new char[capacity];

    size_t converted = 0U;

    //wcstombs(ansiString, unicodeString, _TRUNCATE);
    wcstombs_s(&converted, ansiString, capacity, unicodeString, _TRUNCATE);

    cout << "ANSI string:" << endl;
    cout << "\tLength: " << strlen(ansiString) << " characters" << endl;
    cout << "\tSize: " << capacity * sizeof(ansiString[0]) << " bytes" << endl;

    cout << endl;
    cout << "Unicode string:" << endl;
    cout << "\tLength: " << length << " characters" << endl;
    cout << "\tSize: " << sizeof(unicodeString) << " bytes" << endl;

    delete[] ansiString;

    return 0;
}