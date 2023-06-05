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

void Initialize(vector<vector<ll>> &m1, vector<ll> &coefi)
{
    for (int i = 0; i < m1.size(); i++)
    {
        m1[0][i] = coefi[i];
    }
    for (int i = 1; i < m1.size(); i++)
    {
        m1[i][i - 1] = 1;
    }
    // for (auto x : m1)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
}

ll Matrix_Exponentiaiton(vector<ll> &ai, vector<ll> &coefi, ll n, ll k)
{
    reverse(ai.begin(), ai.end());
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    Identity(res);
    vector<vector<ll>> T(n, vector<ll>(n, 0));
    Initialize(T, coefi);
    k -= n;
    while (k)
    {
        if (k & 1)
            res = Multiply(res, T);
        T = Multiply(T, T);
        k >>= 1;
    }
    ll result = 0;
    // for (int i = 0; i < n; i++)
    //     cout << ai[i] << "\n";
    for (int i = 0; i < n; i++)
    {
        result += (res[0][i] % mod) * (ai[i] % mod);
        result %= mod;
    }
    return result;
}

ll Ways(ll n, ll j)
{
    vector<ll> coefi(j, 1);
    vector<ll> ai(j, 1);
    for (int i = 1; i < j; i++)
    {
        for (int k = i; k >= 1; k--)
        {
            ai[i] += ai[k - 1];
        }
    }
    return Matrix_Exponentiaiton(ai, coefi, j, n);
}

int main()
{
    ll n = 1e17, j = 10;
    // cin >> n >> j;
    cout << Ways(n, j) << "\n";
    return 0;
}