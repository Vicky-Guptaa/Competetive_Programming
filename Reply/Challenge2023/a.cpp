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

bool mycomp(pll &a, pll &b)
{
    return a.first > b.first;
}

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

ll scorer(vector<vector<bool>> &is_snake_vis, vector<vector<ll>> &snake_val)
{
    int n = is_snake_vis.size();
    int m = is_snake_vis[0].size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (is_snake_vis[i][j])
            {
                ans += snake_val[i][j];
            }
        }
    }
    return ans;
}

string dijkstra(int i, int j, int r, int c, int s, ll &timer, vector<vll> &grid, vector<vector<bool>> &isWarmHole, vector<vector<ll>> &isvisit, int itr)
{
    vector<int> moveX = {0, 0, -1, 1}, moveY = {1, -1, 0, 0};
    string moveS = "RLUD";
    priority_queue<pair<ll, pair<vector<ll>, string>>> pque;
    pque.push({0, {{i, j, 1}, ""}});
    isvisit[i][j] = itr;
    while (!pque.empty() && timer > 0)
    {
        ll x = pque.top().second.first[0];
        ll y = pque.top().second.first[1];
        ll time = pque.top().second.first[2];
        string curr = pque.top().second.second;
        ll sum = pque.top().first;
        pque.pop();
        if (timer == time)
        {
            return curr;
        }
        int indx = 0;
        for (int i = 0; i < 4; i++)
        {
            int _x = x + moveX[i], _y = y + moveY[i];
            if (_x >= r || _y >= c || _x < 0 || _y < 0 || isWarmHole[_x][_y] || isvisit[_x][_y])
                continue;
            pque.push({sum + grid[_x][_y], {{_x, _y, time + 1}, curr + " " + moveS[i]}});
            isvisit[_x][_y] = itr;
        }
    }
    fl(i, 0, r)
    {
        fl(j, 0, c)
        {
            if (isvisit[i][j] == itr)
            {
                isvisit[i][j] = 0;
            }
        }
    }
    return "";
}

void helper(int r, int c, int s, vll &snakes, vector<vll> &grid, vector<vector<bool>> &isWarmHole)
{
    vector<vector<ll>> isvisit(r, vector<ll>(c, false));
    vector<string> path;

    // vpll snk;
    // fl(i, 0, snakes.size())
    // {
    //     snk.push_back({snakes[i], i});
    // }
    // sort(vr(snk), mycomp);
    // for (auto x : snk)
    // {
    //     cout << x << "\n";
    // }
    // cout << "\n\n";
    ll itr = 0;
    fl(i, 0, r)
    {
        fl(j, 0, c)
        {
            if (itr == snakes.size())
                break;
            if (!isvisit[i][j] && !isWarmHole[i][j])
            {
                ll timer = snakes[itr];
                string currPath = dijkstra(i, j, r, c, s, timer, grid, isWarmHole, isvisit, itr);
                if (!currPath.empty())
                {
                    path.push_back(to_string(j) + " " + to_string(i) + currPath);
                    itr++;
                }
            }
        }
        if (itr == snakes.size())
            break;
    }
    for (auto x : path)
    {
        cout << x << "\n";
    }
}

// Code
void solve()
{
    int r, c, s;
    cin >> c >> r >> s;
    vector<ll> snakes(s);
    for (int i = 0; i < s; i++)
        cin >> snakes[i];
    vector<vector<ll>> grid(r, vector<ll>(c, 0));
    vector<vector<bool>> isWarmHole(r, vector<bool>(c, 0));
    map<ll, set<pair<int, int>>> valPositions;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            string s;
            cin >> s;
            if (s[0] == '-')
                grid[i][j] = -1ll * stoll(s);
            else if (s[0] == '*')
            {
                grid[i][j] = INT_MIN;
                isWarmHole[i][j] = 1;
            }
            else
                grid[i][j] = stoll(s);
        }
    }
    helper(r, c, s, snakes, grid, isWarmHole);
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
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    You Can Do_It
    //     ll t;
    // cin >> t;
    // fl(i, 0, t)
    // {
    solve();
    // }
    // solve();
    // fl(i,0,t) //Kickstart
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    //     cout<<'\n';
    // }
    return 0;
}
