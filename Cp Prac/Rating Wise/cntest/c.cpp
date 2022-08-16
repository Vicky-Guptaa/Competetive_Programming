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
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Sorting
bool sortpa(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortpd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

// Bits
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

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
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
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

// ll solve2()
// {
//     ll n, q;
//     cin >> n >> q;
//     vll arr(n);
//     cin >> arr;
//     deque<pll> dque, ref;
//     fl(i, 0, n)
//     {
//         dque.push_back({arr[i], i + 1});
//     }
//     ref = dque;
//     map<int, int>
//         score;
//     for (int i = 0; i < n; i++)
//     {
//         auto num1 = dque.front();
//         dque.pop_front();
//         auto num2 = dque.front();
//         dque.pop_front();
//         if (num1.first > num2.first)
//         {
//             score[num1.second]++;
//             dque.push_front(num1);
//             dque.push_back(num2);
//         }
//         else
//         {
//             score[num2.second]++;
//             dque.push_front(num2);
//             dque.push_back(num1);
//         }
//     }
//     int mxIndx = max_element(vr(arr)) - arr.begin();
//     ll ans;
//     while (q--)
//     {
//         ll a, b;
//         cin >> a >> b;
//         if (b >= n - 1)
//         {
//             if (mxIndx + 1 != a)
//             {
//                 // cout << score[a] << "\n";
//                 ans = score[a];
//             }
//             else
//             {
//                 ll scr = b - n + score[mxIndx + 1];
//                 // cout << scr << "\n";
//                 ans = scr;
//             }
//         }
//         else
//         {
//             dque = ref;
//             mll temp;
//             for (int i = 0; i < b; i++)
//             {
//                 auto num1 = dque.front();
//                 dque.pop_front();
//                 auto num2 = dque.front();
//                 dque.pop_front();
//                 if (num1.first > num2.first)
//                 {
//                     temp[num1.second]++;
//                     dque.push_front(num1);
//                     dque.push_back(num2);
//                 }
//                 else
//                 {
//                     temp[num2.second]++;
//                     dque.push_front(num2);
//                     dque.push_back(num1);
//                 }
//             }
//             // cout << temp[a] << "\n";
//             ans = temp[a];
//         }
//     }
//     return ans;
// }

// Code
void solve()
{
    ll n, q;
    cin >> n >> q;
    vll arr(n);
    cin >> arr;
    deque<pll> dque, ref;
    fl(i, 0, n)
    {
        dque.push_back({arr[i], i + 1});
    }
    ref = dque;
    map<int, map<int, int>>
        score;
    for (int i = 1; i < n; i++)
    {
        auto num1 = dque.front();
        dque.pop_front();
        auto num2 = dque.front();
        dque.pop_front();
        if (num1.first > num2.first)
        {
            score[i][num1.second]++;
            dque.push_front(num1);
            dque.push_back(num2);
        }
        else
        {
            score[i][num2.second]++;
            dque.push_front(num2);
            dque.push_back(num1);
        }
    }
    vector<vector<int>> match(n + 1);
    for (auto x : score)
    {
        for (auto y : x.second)
        {
            match[y.first].push_back(x.first);
        }
    }

    int mxIndx = max_element(vr(arr)) - arr.begin();
    ll ans;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (b >= n - 1)
        {
            if (mxIndx + 1 != a)
            {
                // cout << match[a].size() << "\n";
                ans = match[a].size();
            }
            else
            {
                ll scr = b - n + 1 + match[a].size();
                // cout << scr << "\n";
                ans = scr;
            }
        }
        else
        {
            auto indx = lower_bound(vr(match[a]), b);
            if (indx == match[a].end())
            {
                // cout << match[a].size() << "\n";
                ans = match[a].size();
            }
            else
            {
                int index = lower_bound(vr(match[a]), b) - match[a].begin();
                if (index == 0 && (match[a].empty() || match[a][index] > b))
                {
                    // cout << "0\n";
                    ans = 0;
                }
                else if (index == 0 || match[a][index] == b)
                {

                    // cout << ++indx << "\n";
                    ans = ++index;
                }
                else
                {
                    // cout << index << "\n";
                    ans = index;
                }
            }
        }
        cout << ans << "\n";
    }
}
/*
When you are coding,remember to:
      - clear the arrays if a problem has many tasks.
      - pay attention to some special cases(n=0,1).
      - Don't code before think completely.
      - ...
*/
// Main

// void solve()
// {
//     int n = rand() % 10 + 2;
//     int k = 1;
//     vll arr(n);
//     set<int> oset;
//     fl(i, 0, n)
//     {
//         oset.insert(i + 1);
//     }
//     for (int i = 0; i < n; i++)
//     {

//     }
// }

int main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("Input.txt", "r", stdin);
    //    freopen("Output.txt", "w", stdout);
    //#endif
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
