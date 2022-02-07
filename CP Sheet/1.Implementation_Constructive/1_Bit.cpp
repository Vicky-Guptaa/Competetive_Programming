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
    int result = 0;
    while (t--)
    {
        string s;
        cin >> s;
        if (s[0] == '-' || s[2] == '-')
        {
            result--;
        }
        else
        {
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}