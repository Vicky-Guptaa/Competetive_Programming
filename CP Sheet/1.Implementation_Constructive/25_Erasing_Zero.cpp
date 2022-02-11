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
    while (s.length() > 1 && s[0] == '0')
        s.substr(1);
    cout << s;
    return 0;
}