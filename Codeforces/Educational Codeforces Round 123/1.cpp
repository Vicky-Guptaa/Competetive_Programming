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
        vector<bool> key(3, 0);
        bool isWin = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'r')
            {
                key[0] = 1;
            }
            else if (s[i] == 'b')
            {
                key[1] = 1;
            }
            else if (s[i] == 'g')
            {
                key[2] = 1;
            }
            else if (s[i] == 'R')
            {
                if (key[0] == 0)
                {
                    isWin = 0;
                    break;
                }
            }
            else if (s[i] == 'B')
            {
                if (key[1] == 0)
                {
                    isWin = 0;
                    break;
                }
            }
            else if (s[i] == 'G')
            {
                if (key[2] == 0)
                {
                    isWin = 0;
                    break;
                }
            }
        }
        if (isWin)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}