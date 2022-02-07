#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 1e9;

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
                result[i][j] += (m1[i][k] % mod) * (m2[k][j] % mod);
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> ai(n), coefi(n);
        for (auto &x : ai)
            cin >> x;
        for (auto &x : coefi)
            cin >> x;
        int k;
        cin >> k;
        if (k <= n)
        {
            cout << ai[k - 1] << "\n";
        }
        else
            cout << Matrix_Exponentiaiton(ai, coefi, n, k) << "\n";
    }
    return 0;
}