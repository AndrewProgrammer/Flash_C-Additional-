#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char ansiString[] = "mbstowcs converts ANSI string to Unicode string";

    unsigned int length = strlen(ansiString);
    unsigned int capacity = length + 1U;

    wchar_t* unicodeString = new wchar_t[capacity];

    size_t converted = 0U;

    //mbstowcs(unicodeString, ansiString, _TRUNCATE);
    mbstowcs_s(&converted, unicodeString, capacity, ansiString, _TRUNCATE);

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