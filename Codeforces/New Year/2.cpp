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
        int n;
        cin >> n;
        string str;
        cin >> str;
        int index = 0;
        if (n == 1 || str[0] == str[1])
        {
            cout << str[0] << str[0] << "\n";
            continue;
        }
        index = n;
        for (int i = 1; i < n; i++)
        {
            if (str[i - 1] < str[i])
            {
                index = i;
                break;
            }
        }
        for (int i = 0; i < index; i++)
        {
            cout << str[i];
        }
        for (int i = index - 1; i >= 0; i--)
        {
            cout << str[i];
        }
        cout << "\n";
    }
    return 0;
}