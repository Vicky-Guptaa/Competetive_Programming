#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

ll sum(ll a, ll b, ll mod = 1e9 + 7)
{
    return (a + b) % mod;
}

ll diff(ll a, ll b, ll mod = 1e9 + 7)
{
    return ((a - b) % mod + mod) % mod;
}

ll product(ll a, ll b, ll mod = 1e9 + 7)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
}

ll power(ll a, ll b, ll mod = 1e9 + 7)
{
    ll result = 1;
    while (b != 0)
    {
        if (b & 1)
            result = product(result, a);
        a = product(a, a);
        b /= 2;
    }
    return result;
}

class String_Hash
{
    vector<ll> hash, inv_pow, pow;
    ll size, base, mod;

public:
    String_Hash(string s)
    {
        srand(time(NULL));
        // use random value to avoid soln hacking of hasing
        base = 107;
        // set the prime mod val
        mod = 1e9 + 7;
        size = s.size() + 1;
        hash.resize(size, 0);
        inv_pow.resize(size, 0);
        pow.resize(size, 0);
        // precalc the power and inveerse power
        preCalc();
        // pre calc the hashes
        buildHash(s);
    }
    void preCalc()
    {
        pow[0] = 1;
        for (int i = 1; i < size; i++)
        {
            pow[i] = product(pow[i - 1], base, mod);
        }
        inv_pow[0] = 1;
        ll pw_inv = power(base, mod - 2, mod);
        for (int i = 1; i < size; i++)
        {
            inv_pow[i] = product(inv_pow[i - 1], pw_inv, mod);
        }
    }
    void buildHash(string s)
    {
        hash[0] = 0;
        for (int i = 1; i < size; i++)
        {
            // s[i-1]-'a' +1 bcoz for a val bcoz 0 and product remains 0 so we a to be 1
            hash[i] = sum(hash[i - 1], product(s[i - 1] - 'a' + 1, pow[i - 1], mod), mod);
        }
    }
    ll getHash(int l, int r)
    {
        // 1 based indexing
        ll hres = diff(hash[r], hash[l - 1], mod);
        hres = product(hres, inv_pow[l - 1], mod);
        return hres;
    }
};

int main()
{
    string str = "abcabcabcabcabcabc";
    String_Hash s(str);
    cout << s.getHash(1, 3) << " " << s.getHash(4, 6) << endl;
    return 0;
}