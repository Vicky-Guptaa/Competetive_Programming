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
    ll total = 0;
    while (t--)
    {
        string s;
        cin >> s;
        if (s[0] == 'T')
            total += 4;
        else if (s[0] == 'C')
            total += 6;
        else if (s[0] == 'O')
            total += 8;
        else if (s[0] == 'D')
            total += 12;
        else
            total += 20;
    }
    cout << total << "\n";
    return 0;
}
/*
3
Dodecahedron
Octahedron
Octahedron

*/