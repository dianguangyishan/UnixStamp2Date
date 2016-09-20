#include <iostream>
#include "Stamp.h"
#include <string>


int main()
{
    time_t n;
    cout << 483647-397247 <<endl;
    while (cin >> n)
    {
        Stamp test(n);
        cout << test.getTime()<< endl;
        cout << test.year  << endl;
        cout << test.month << endl;
        cout << test.day << endl;
        cout << test.hour << endl;
        cout << test.minute << endl;
        cout << test.second << endl;
    }
    cout << 483647-397247 <<endl;
    return 0;
}

