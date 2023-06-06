// Vicky_Gupta
#include <iostream>
#include <bits/stdc++.h>
// #include <sys/resource.h>

using namespace std;
// using namespace chrono;

/* _______________Policy Based DS______________*/
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >;
// provides find_by_order, order_of_key
/*_____________________________________________*/

// def
// #define Vicky_Gupta 1

// Speed
#define You ios_base::sync_with_stdio(false);
#define Can cin.tie(NULL);
#define Do_It cout.tie(NULL);

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long;

// Constants
const lld pi = 3.141592653;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<int, int> ppi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ppi> vpi;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, s, n) for (int i = s; i < n; i++)
#define rl(i, n, s) for (int i = n; i >= s; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()

// Debug
#ifdef Vicky_Gupta
#define debug(x)       \
    cerr << #x << " "; \
    cerr << x << " ";  \
    cerr << endl;
#else
#define debug(x) ;
#endif

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions
template <typename T>
void print(T &&t) { cout << t << '\n'; }
void printarr(ll arr[], ll s, ll n)
{
    fl(i, s, n) cout << arr[i] << " ";
    cout << '\n';
}
template <typename T>
void printvec(vector<T> v)
{
    ll n = v.size(), s = 0;
    fl(i, s, n) cout << v[i] << " ";
    cout << '\n';
}

// Mathematical functions
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
            result = product(result, a, mod);
        a = product(a, a, mod);
        b /= 2;
    }
    return result;
}

ll division(ll a, ll b, ll mod = 1e9 + 7)
{
    return (product(a, power(b, mod - 2, mod), mod));
}

vector<ll> fact(1e6 + 2, 1);

void factorial(ll mod = 1e9 + 7)
{
    ll f = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        f *= i;
        f %= mod;
        fact[i] = f;
    }
}

ll nCr(ll n, ll r, ll mod = 1e9 + 7)
{
    return product(fact[n], power(product(fact[n - r], fact[r], mod), mod - 2, mod), mod);
}
// Sorting
bool sortpa(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortpd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Check
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n) { return (n & (n - 1)) == 0; }
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

// Code by Vicky Gupta
// Language C++

// accumulate(first, last, sum);
// max_element(first, last);
// min_element(first, last);
//__builtin_popcount(n); for int
//__builtin_popcountll(x); for long long
//__builtin_clz(x); for int
//__builtin_clzll(x); for long long

class DString_Hash
{
    vector<pair<ll, ll>> hash, inv_pow, pow;
    ll size, base, mod1, mod2;

public:
    DString_Hash(string s)
    {
        srand(time(NULL));
        // use random value to avoid soln hacking of hasing
        base = 107;
        // set the prime mod val use random big prime to avoid hacking of soln
        mod2 = 1e9 + 21;
        mod1 = 1e9 + 7;
        size = s.size() + 1;
        hash.resize(size);
        inv_pow.resize(size);
        pow.resize(size);
        // precalc the power and inveerse power
        preCalc();
        // pre calc the hashes
        buildHash(s);
    }
    void preCalc()
    {
        pow[0].first = 1;
        pow[0].second = 1;
        for (int i = 1; i < size; i++)
        {
            pow[i].first = product(pow[i - 1].first, base, mod1);
            pow[i].second = product(pow[i - 1].second, base, mod2);
        }
        inv_pow[0].first = 1;
        inv_pow[0].second = 1;
        pair<ll, ll> pw_inv;
        pw_inv.first = power(base, mod1 - 2, mod1);
        pw_inv.second = power(base, mod2 - 2, mod2);

        for (int i = 1; i < size; i++)
        {
            inv_pow[i].first = product(inv_pow[i - 1].first, pw_inv.first, mod1);
            inv_pow[i].second = product(inv_pow[i - 1].second, pw_inv.second, mod2);
        }
    }
    void buildHash(string s)
    {
        hash[0].first = 0;
        hash[0].second = 0;
        for (int i = 1; i < size; i++)
        {
            // s[i-1]-'a' +1 bcoz for a val bcoz 0 and product remains 0 so we a to be 1
            hash[i].first = sum(hash[i - 1].first, product(s[i - 1] - 'a' + 1, pow[i - 1].first, mod1), mod1);
            hash[i].second = sum(hash[i - 1].second, product(s[i - 1] - 'a' + 1, pow[i - 1].second, mod2), mod2);
        }
    }
    pair<ll, ll> getHash(int l, int r)
    {
        // 1 based indexing
        pair<ll, ll> hres;
        hres.first = diff(hash[r].first, hash[l - 1].first, mod1);
        hres.first = product(hres.first, inv_pow[l - 1].first, mod1);

        hres.second = diff(hash[r].second, hash[l - 1].second, mod2);
        hres.second = product(hres.second, inv_pow[l - 1].second, mod2);

        return hres;
    }
};
// use 1 based indexing

// Code
void solve()
{
    ll n;
    cin >> n;
}
/*
When you are coding,remember to:
      - clear the arrays if a problem has many tasks.
      - pay attention to some special cases(n=0,1).
      - Don't code before think completely.
      - ...
*/
// Main
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    // #endif
    You Can Do_It
    //     ll t;
    // cin >> t;
    // fl(i, 0, t)
    // {
    //     solve();
    // }
    solve();
    // fl(i,0,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    //     cout<<'\n';
    // }
    return 0;
}
