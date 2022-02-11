#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int myAtoi(string s)
{
    int n = s.length();
    string str;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        else if (s[i] != '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))
        {
            if (s[i] == '+' || s[i] == '-')
                i++;
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                str += s[i];
                i++;
            }
            return stoi(str);
        }
        else
            break;
    }
    return 0;
}

int main()
{
    cout << myAtoi("12") << "\n";
    return 0;
}