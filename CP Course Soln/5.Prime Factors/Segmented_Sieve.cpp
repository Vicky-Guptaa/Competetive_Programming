#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> Prime_Sieve(ll n)
{
    vector<bool> prime_bool(n + 1, 1);
    prime_bool[0] = prime_bool[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (prime_bool[i] == false)
            continue;
        for (ll j = i * i; j <= n; j += i)
        {
            prime_bool[j] = false;
        }
    }
    vector<ll> Prime;
    for (ll i = 2; i <= n; i++)
    {
        if (prime_bool[i] == 1)
            Prime.push_back(i);
    }
    return Prime;
}

vector<int> Segmented_Sieve(int m, int n, vector<ll> Prime)
{
    vector<bool> isPrime_Number(n - m + 1, 1);
    for (auto &prime : Prime)
    {
        if (prime * prime > n)
            break;
        int start = (m / prime) * prime;
        if (prime >= m && prime <= n)
        {
            start = 2 * prime;
        }
        for (int i = start; i <= n; i += prime)
        {
            if (i < m)
                continue;
            isPrime_Number[i - m] = false;
        }
    }
    vector<int> Ans;
    for (int i = m; i <= n; i++)
    {
        if (isPrime_Number[i - m] == 1 && i != 0 && i != 1)
            Ans.push_back(i);
    }
    return Ans;
}

int main()
{
    vector<ll> Prime = Prime_Sieve(1e5);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> Result = Segmented_Sieve(m, n, Prime);
        for (auto x : Result)
        {
            cout << x << "\n";
        }
        cout << "\n";
    }
    return 0;
}