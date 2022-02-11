#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.length();
        int index = 1;
        bool isTwo = false;
        for (int i = 1; i < n; i++)
        {
            int d1 = str[i - 1] - '0';
            int d2 = str[i] - '0';
            if (d1 + d2 > 9)
            {
                index = i;
                isTwo = true;
            }
        }
        if (!isTwo)
        {
            int d1 = str[0] - '0';
            int d2 = str[1] - '0';
            cout << d1 + d2 << str.substr(2) << "\n";
        }
        else
        {
            int d1 = str[index - 1] - '0';
            int d2 = str[index] - '0';
            cout << str.substr(0, index - 1) << d1 + d2 << str.substr(index + 1) << "\n";
        }
    }
    return 0;
}