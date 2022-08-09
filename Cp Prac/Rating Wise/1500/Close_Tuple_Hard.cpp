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

// Sorting
bool sortpa(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortpd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Code by Vicky Gupta
// Language C++

// accumulate(first, last, sum);
// max_element(first, last);
// min_element(first, last);
//__builtin_popcount(n); for int
//__builtin_popcountll(x); for long long
//__builtin_clz(x); for int
//__builtin_clzll(x); for long long

// Code

ll sum(ll a, ll b)
{
    return (a + b) % mod;
}

ll diff(ll a, ll b)
{
    return ((a - b) % mod + mod) % mod;
}

ll product(ll a, ll b)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
}

ll power(ll a, ll b)
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

ll division(ll a, ll b)
{
    return (product(a, power(b, mod - 2)));
}

vector<long long> fact(2e5 + 1, 1);
void factorial()
{
    fact[1] = 1;
    for (int i = 2; i <= 2e5 + 1; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
}

ll nCr(ll n, ll r)
{
    return product(fact[n], power(product(fact[n - r], fact[r]), mod - 2));
}
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vll arr(n);
    vpll temp;
    cin >> arr;
    sort(vr(arr));
    ll itr = m - 1, ans = 0;
    fl(i, 0, n)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        while (itr < n && arr[itr] - arr[i] <= k)
            itr++;
        temp.push_back({i, itr});
        if (itr - i >= m)
            ans += nCr(itr - i, m);
        ans %= mod;
        if (itr == n)
            break;
    }
    fl(i, 1, temp.size())
    {
        if (temp[i].first < temp[i - 1].second)
        {
            if (temp[i - 1].second - temp[i].first >= m)
            {
                ans -= nCr(temp[i - 1].second - temp[i].first, m);
                ans = (ans + mod) % mod;
            }
        }
    }
    cout
        << ans << "\n";
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
    //#ifndef ONLINE_JUDGE
    //    freopen("Input.txt", "r", stdin);
    //    freopen("Output.txt", "w", stdout);
    //#endif
    You Can Do_It
    factorial();
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
