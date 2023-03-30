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

string hehe = "";
ll meme = 10;

ll helper(int strt, string &s, string &e, bool sristrict, bool eristrict, ll mn, ll mx, vector<vector<vector<vector<vi>>>> &dp, string &sres)
{
    if (strt == s.size())
    {
        if (meme > mx - mn)
        {
            meme = mx - mn;
            hehe = sres;
        }
        return mx - mn;
    }

    if (dp[strt][mn][mx][sristrict][eristrict] != -1)
        return dp[strt][mn][mx][sristrict][eristrict];

    ll end = (eristrict) ? e[strt] - '0' : 10;
    ll start = (sristrict) ? s[strt] - '0' : 0;
    sres[strt] = '0' + start;
    ll res = helper(strt + 1, s, e, sristrict, start == end, min(mn, start), max(mx, start), dp, sres);
    for (ll i = start + 1; i < end; i++)
    {
        sres[strt] = char(i + '0');
        ll calc = helper(strt + 1, s, e, false, false, min(mn, i), max(mx, i), dp, sres);
        if (calc < res)
        {
            res = calc;
        }
    }
    if (eristrict && start != end)
    {
        sres[strt] = char(end + '0');
        ll calc = helper(strt + 1, s, e, start == end, eristrict, min(mn, end), max(mx, end), dp, sres);
        if (calc < res)
        {
            res = calc;
        }
    }
    return dp[strt][mn][mx][sristrict][eristrict] = res;
}

// Code
void solve()
{
    hehe = "";
    meme = 10;
    ll l, r;
    cin >> l >> r;
    vector<vector<vector<vector<vi>>>> dp(20, vector<vector<vector<vi>>>(10, vector<vector<vi>>(10, vector<vi>(2, vi(2, -1)))));
    string rstr = to_string(r);
    string lstr = to_string(l);
    if (lstr.size() == 1)
    {
        cout << lstr << "\n";
        return;
    }
    if (lstr.size() < rstr.size())
    {
        fl(i, 0, lstr.size())
        {
            cout << "9";
        }
        cout << "\n";
        return;
    }
    string res = "-------------------";
    ll help = helper(0, lstr, rstr, true, true, 9, 0, dp, res);
    fl(i, 0, hehe.size())
    {
        if (hehe[i] == '-')
        {
            hehe = hehe.substr(0, i);
            break;
        }
    }
    ll ans = stoll(hehe);
    if (ans == 0)
    {
        while (lstr.front() == '0')
            lstr = lstr.substr(1);
        fl(i, 0, lstr.size())
        {
            cout << lstr.front();
        }
        cout << "\n";
        return;
    }
    cout << hehe << "\n";
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
