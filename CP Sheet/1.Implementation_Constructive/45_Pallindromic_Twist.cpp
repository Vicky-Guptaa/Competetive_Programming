#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool isPallindrime(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (isPallindrime(s))
        {
            cout << "YES\n";
        }
        else
        {
            bool isTrue = 1;
            for (int i = 0; i < s.size() / 2; i++)
            {
                int diff = abs(s[i] - s[s.size() - 1 - i]);
                if (diff != 2 && diff != 0)
                {
                    isTrue = 0;
                }
            }
            if (isTrue)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}