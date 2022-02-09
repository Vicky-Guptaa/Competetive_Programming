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
    if (s[0] >= 97 && s[0] <= 122)
    {
        s[0] -= 32;
    }
    cout << s << "\n";
    return 0;
}