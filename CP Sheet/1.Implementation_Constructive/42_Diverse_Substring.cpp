#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] != s[i])
        {
            cout << "YES\n";
            cout << s[i - 1] << s[i] << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}