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
    bool isTrue = true;
    int fc = 0, sc = 0;
    for (auto x : s)
    {
        if (x == '4')
            fc++;
        else if (x == '7')
            sc++;
    }
    if (sc + fc == 4 || sc + fc == 7)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}