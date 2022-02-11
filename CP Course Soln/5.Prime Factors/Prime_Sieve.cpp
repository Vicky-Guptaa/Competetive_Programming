#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<bool> Prime_Sieve(ll n)
{
    vector<bool> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (prime[i] == false)
            continue;
        for (ll j = i * i; j <= n; j += i)
        {
            prime[j] = false;
        }
    }
    return prime;
}

int main()
{
    ll n;
    cin >> n;
    vector<bool> result = Prime_Sieve(n);
    for (int i = 0; i <= n; i++)
    {
        if (result[i] == true)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}