#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool isEqual(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i - 1]) != (arr[i]))
            return false;
    }
    return true;
}

vector<int> Prime_Sieve(ll n = 1e6 + 1)
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

void Prime_Factor_Sieve(ll n, vector<int> &Sieve, vector<int> &freq)
{
    while (Sieve[n] != 1)
    {
        freq[Sieve[n]]++;
        n /= Sieve[n];
    }
    if (n != 1)
        freq[n]++;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    vector<int> prime = Prime_Sieve();
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<int> freq(1e6 + 1, 0);
        for (auto &x : arr)
        {
            cin >> x;
        }
        int gcd = 0;
        if (isEqual(arr))
        {
            cout << "0\n";
            continue;
        }
        for (auto &x : arr)
            gcd = __gcd(x, gcd);
        if (gcd != 1)
        {
            cout << "1\n";
            cout << gcd << "\n";
            continue;
        }
        for (auto &x : arr)
        {
            Prime_Factor_Sieve(x, prime, freq);
        }
        bool isFound = false;
        for (int i = 2; i <= m; i++)
        {
            if (!freq[i] && prime[i] == 1)
            {
                isFound = true;
                cout << "1\n";
                cout << i << "\n";
                break;
            }
        }
        if (isFound)
            continue;
        cout << "2\n";
        cout << 2 << "\n"
             << 3 << "\n";
    }
    return 0;
}
