#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int Gcd_Recur(int n, int m)
{
    if (m == 0)
        return n;
    return Gcd_Recur(m, n % m);
}

int Gcd_Iterative(int n, int m)
{
    while (m != 0)
    {
        int temp = m;
        m = n % m;
        n = temp;
    }
    return n;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << Gcd_Recur(n, m) << "\n";
    cout << Gcd_Iterative(n, m) << "\n";
    return 0;
}