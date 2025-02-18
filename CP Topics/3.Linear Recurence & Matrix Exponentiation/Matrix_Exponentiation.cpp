#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

vector<vector<ll>> Multiply(vector<vector<ll>> &m1, vector<vector<ll>> &m2)
{
    int n = m1.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += m1[i][k] * m2[k][j];
                result[i][j] %= mod;
            }
        }
    }
    return result;
}

void Identity(vector<vector<ll>> &m1)
{
    int n = m1.size();
    for (int i = 0; i < n; i++)
        m1[i][i] = 1;
}

ll Matrix_Exponentiation(ll n)
{
    vector<vector<ll>> res(2, vector<ll>(2, 0));
    Identity(res);
    vector<vector<ll>> T(2, vector<ll>(2, 0));
    T[0][0] = T[0][1] = T[1][0] = 1;
    if (n <= 2)
        return 1;
    n -= 2;
    while (n)
    {
        if (n & 1)
            res = Multiply(res, T);
        T = Multiply(T, T);
        n /= 2;
    }
    // The F(n) Matrix As F(1)=1 F(2)=1
    vector<int> F1(2, 1);
    // Multiply F(n) With T Matrix We Have To Only Multiply
    // The First Row Of T With First Col OF F
    ll result = 0;
    for (int i = 0; i < 2; i++)
    {
        result += (F1[i] * res[0][i]) % mod;
    }
    return result;
}

int main()
{
    cout << Matrix_Exponentiation(10);
    return 0;
}