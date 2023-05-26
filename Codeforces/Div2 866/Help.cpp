#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int helper(int strt, string s, int k)
{
    if (strt == s.size())
        return 1;
    long long num = 0, ways = 0, mod = 1e9 + 7;
    for (int i = strt + 1; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            ways += helper(i, s, k);
            ways %= mod;
        }
        num = num * 10 + (s[i] - '0');
        if (num > k)
            break;
    }
    return ways;
}

int numberOfArrays(string s, int k)
{
    return helper(-1, s, k);
}

int main()
{

    cout << numberOfArrays("1000", 10000) << "\n";
    return 0;
}