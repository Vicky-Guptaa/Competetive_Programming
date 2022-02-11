#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0, j = s.length() - 1;
        for (int p = 0; p <= j; p++)
        {
            if (s[p] == '0')
                i++;
            else
                break;
        }
        for (int p = j; p >= 0; p--)
        {
            if (s[p] == '0')
                j--;
            else
                break;
        }
        if (i >= j)
        {
            cout << "0\n";
        }
        else
        {
            int count = 0;
            for (int p = i; p <= j; p++)
            {
                if (s[p] == '0')
                    count++;
            }
            cout << count << "\n";
        }
    }
    return 0;
}