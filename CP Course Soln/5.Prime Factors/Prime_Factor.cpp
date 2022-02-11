#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> Prime_Sieve(ll n)
{
    vector<int> prime(n + 1, 1);
    for (ll i = 2; i <= n; i++)
    {
        if (prime[i] != 1)
            continue;
        for (ll j = i * i; j <= n; j += i)
        {
            prime[j] = i;
        }
    }
    return prime;
}

vector<ll> Prime_Factor_Brute(ll n)
{
    vector<ll> ans;
    for (ll i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    return ans;
}

vector<ll> Prime_Factor_Opti(ll n)
{
    vector<ll> ans;
    ll temp = n;
    for (ll i = 2; i * i <= n; i++)
    {
        while (temp % i == 0)
        {
            ans.push_back(i);
            temp /= i;
        }
    }
    if (temp != 1)
        ans.push_back(temp);
    return ans;
}

vector<int> Prime_Factor_Sieve(ll n, vector<int> Sieve)
{
    vector<int> factor;
    while (Sieve[n] != 1)
    {
        factor.push_back(Sieve[n]);
        n /= Sieve[n];
    }
    if (n != 1)
        factor.push_back(n);
    sort(factor.begin(), factor.end());
    return factor;
}

int main()
{
    ll n;
    cin >> n;
    vector<int> Sieve = Prime_Sieve(n);
    vector<int> factor = Prime_Factor_Sieve(n, Sieve);
    for (auto &x : factor)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

/*
999999000001
*/