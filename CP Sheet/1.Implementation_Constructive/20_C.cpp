#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(int a, int b, int n)
{
    int oper = 0;
    int isMy = 0;
    while (a <= n && b <= n)
    {
        if (isMy)
        {
            a += b;
        }
        else
        {
            b += a;
        }
        isMy = !isMy;
        oper++;
    }
    return oper;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        cout << min(solve(a, b, n), solve(b, a, n)) << "\n";
    }
    return 0;
}