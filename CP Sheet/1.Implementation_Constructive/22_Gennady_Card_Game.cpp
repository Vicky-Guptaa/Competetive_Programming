#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool isTrue = 0;
    for (int i = 0; i < 5; i++)
    {
        string p;
        cin >> p;
        if (p[0] == s[0] || p[1] == s[1])
            isTrue = 1;
    }
    if (isTrue)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}