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

ll result(vll arr, vll brr, vll crr)
{
    ll ans = LONG_LONG_MAX;
    fl(i, 0, crr.size())
    {
        ll it1 = lower_bound(vr(arr), crr[i]) - arr.begin();
        ll it2 = upper_bound(vr(brr), crr[i]) - brr.begin();
        ll it3 = i;
        if (it1 == arr.size())
            it1--;
        if (it2 > 0 || it2 >= brr.size())
            it2--;
        ans = min(ans, (arr[it1] - brr[it2]) * (arr[it1] - brr[it2]) +
                           (brr[it2] - crr[it3]) * (brr[it2] - crr[it3]) +
                           (crr[it3] - arr[it1]) * (crr[it3] - arr[it1]));

        it1 = upper_bound(vr(arr), crr[i]) - arr.begin();
        it2 = lower_bound(vr(brr), crr[i]) - brr.begin();
        if (it2 == brr.size())
            it2--;
        if (it1 > 0 || it1 >= arr.size())
            it1--;
        ans = min(ans, (arr[it1] - brr[it2]) * (arr[it1] - brr[it2]) +
                           (brr[it2] - crr[it3]) * (brr[it2] - crr[it3]) +
                           (crr[it3] - arr[it1]) * (crr[it3] - arr[it1]));
    }
    return ans;
}

// Code
void solve()
{
    ll na, nb, nc;
    cin >> na >> nb >> nc;
    vll arr(na), brr(nb), crr(nc);
    cin >> arr >> brr >> crr;
    sort(vr(arr));
    sort(vr(brr));
    sort(vr(crr));
    ll ans = min({
        result(arr, brr, crr),
        result(brr, crr, arr),
        result(crr, arr, brr),
    });

    cout << ans << "\n";
}
/*
When you are coding,remember to:
      - clear the arrays if a problem has many tasks.
      - pay attention to some special cases(n=0,1).
      - Don't code before think completely.
      - ...
      10
1 2 2
1
20 1000000000
872178610 1
2 1 2
1000000000 999999984
115759529
1000000000 999999995
1 1 2
1
1
1 1000000000
2 2 2
1000000000 1000000000
427083434 1000000000
1 5
1 2 2
999999998
269434300 1000000000
396243925 1
2 1 2
537896325 1000000000
1
175621284 1000000000
2 2 1
576678644 741670278
33518934 372961791
1
2 2 1
8 1000000000
58891309 1000000000
1
2 1 1
1 1000000000
1000000000
374002221
2 2 1
1000000000 1000000000
1 765357386
1


722
1563762383970504302
0
1510633636923630422
729042793783786958
451418495746830746
513159310288549158
6936371491423514
783746438625865682
1640829081078791222
*/
// Main
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    // #endif
    You Can Do_It
        ll t;
    cin >> t;
    fl(i, 0, t)
    {
        solve();
    }
    // solve();
    // fl(i,0,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    //     cout<<'\n';
    // }
    return 0;
}
