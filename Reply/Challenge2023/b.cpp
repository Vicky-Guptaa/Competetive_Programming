#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define mod 1000000007
#define umap unordered_map
#define uset unordered_set
#define umset unordered_multiset
#define ummap unordered_multimap
#define sbitc(n) __builtin_popcount👎
#define sbitcll(n) __builtin_popcountll👎
#define PI 3.141592653589793238462
#define imax INT_MAX
#define llmax INT64_MAX - 100
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mkp make_pair
#define dyarr(size)   \
    int *arr          \
    {                 \
        new int[size] \
        {             \
        }             \
    }
#define popb pop_back
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define nl "\n"
#define ff first
#define ss second
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define revl(i, a, b) for (int i = a; i >= b; i--)
#define YouCanDoIt                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#ifndef ONLINE_JUDGE
#define file                           \
    freopen("Error.txt", "w", stderr); \
    freopen("Input.txt", "r", stdin);  \
    freopen("output.txt", "w", stdout);
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#define file
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef long l;
// template <class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key

/*-----------------------------------------------------------------------------------------------------------------------------------*/
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll mexpo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
#define MAXN 100100
vector<int> prime;
int lp[MAXN + 1];
void sieve()
{
    loop(i, 2, MAXN)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= MAXN; ++j)
        {
            lp[i * prime[j]] = prime[j];
        }
    }
}
ll fastexpo(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
    {
        ll val = fastexpo(a, b / 2);
        return val * val;
    }
    else
    {
        ll val = fastexpo(a, b / 2);
        return val * val * a;
    }
}
ll modexpo(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll val = modexpo(a, b / 2ll, m) % m;
    if (b % 2 == 0)
    {
        return (val * val) % m;
    }
    return ((val * val) % m * a % m) % m;
}
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
ll scorer(int r, int c, vector<vector<bool>> &is_snake_vis, vector<vector<ll>> &snake_val)
{
    int n = r, m = c;
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
void helper(int r, int c, int s, vector<ll> &snakes, vector<vector<ll>> &grid, vector<vector<bool>> &isWarmHole, map<ll, set<pair<int, int>>> &valPositions)
{
    vector<vector<bool>> isvisit(r, vector<bool>(c, false));
    vector<int> moveX = {0, 0, -1, 1}, moveY = {1, -1, 0, 0};
    for (int i = 0; i < s; i++)
    {
        queue<pair<int, int>> que;
        que.push({valPositions.rbegin()->second.begin()->first, valPositions.rbegin()->second.begin()->second});
        valPositions.rbegin()->second.erase(valPositions.rbegin()->second.begin());
        if (valPositions.rbegin()->second.size())
        {
            valPositions.erase(valPositions.rbegin()->first);
        }
        isvisit[que.front().first][que.front().second] = true;

        int timer = snakes[i] - 1;
        while (!que.empty() && timer > 0)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            timer--;
            pair<ll, pair<int, int>> temp = {(ll)-1e12, {0, 0}};
            for (int i = 0; i < 4; i++)
            {
                int _x = x + moveX[i], _y = y + moveY[i];
                if (_x >= r || _y >= c || _x < 0 || _y < 0 || isWarmHole[_x][_y] || isvisit[_x][_y])
                    continue;
                if (temp.first < grid[_x][_y])
                {
                    temp = {grid[_x][_y], {_x, _y}};
                }
            }
            isvisit[temp.second.first][temp.second.second] = true;
            valPositions[grid[temp.second.first][temp.second.second]].erase({temp.second.first, temp.second.second});
            if (valPositions[grid[temp.second.first][temp.second.second]].size() == 0)
            {
                valPositions.erase(grid[temp.second.first][temp.second.second]);
            }

            que.push({temp.second.first, temp.second.second});
        }
    }
    cout << scorer(r, c, isvisit, grid) << "\n";
}
vector<string> dir;
void dfs(int r, int c, int sr, int sc, int &fr, int &fc, vector<vector<ll>> &grid, vector<vector<bool>> &vis, int len, string str, bool &f)
{
    vis[sr][sc] = 1;
    if (len == 1)
    {
        fr = sr;
        fc = sc;
        f = 1;
        dir.pb(str);
        return;
    }
    if (sr - 1 >= 0 && grid[sr - 1][sc] != INT_MIN && !vis[sr - 1][sc] && !f)
    {
        dfs(r, c, sr - 1, sc, fr, fc, grid, vis, len - 1, str + "U ", f);
    }
    if (sc + 1 < c && grid[sr][sc + 1] != INT_MIN && !vis[sr][sc + 1] && !f)
    {
        // str+='R';
        // str+=' ';
        dfs(r, c, sr, sc + 1, fr, fc, grid, vis, len - 1, str + "R ", f);
    }
    if (sr + 1 < r && grid[sr + 1][sc] != INT_MIN && !vis[sr + 1][sc] && !f)
    {
        // str+='D';
        // str+=' ';
        dfs(r, c, sr + 1, sc, fr, fc, grid, vis, len - 1, str + "D ", f);
    }
    if (sc - 1 >= 0 && grid[sr][sc - 1] != INT_MIN && !vis[sr][sc - 1] && !f)
    {
        // str+='L';
        // str+=' ';
        dfs(r, c, sr, sc - 1, fr, fc, grid, vis, len - 1, str + "L ", f);
    }
    if (!f)
        vis[sr][sc] = 0;
    return;
}
void solver(int r, int c, int s, vector<vector<ll>> &grid, vector<ll> &snakes)
{
    vector<vector<bool>> vis(r, vector<bool>(c, 0));
    int sr = 0, sc = 0;
    vector<pii> vs;

    // sort(snakes.begin(), snakes.end(), greater<ll>());
    int itr = 0;
    for (int i = 0; i < vis.size(); i++)
    {
        for (int j = 0; j < vis[i].size(); j++)
        {
            if (grid[i][j] == INT_MIN || vis[i][j])
            {
                continue;
            }
            bool f = 0;
            dfs(r, c, sr, sc, i, j, grid, vis, snakes[i], "", f);
            vs.pb({sr, sc});
        }
        cout << "\n";
    }
    for (int i = 0; i < s; i++)
    {

        while (grid[sr][sc] == INT_MIN || vis[sr][sc])
        {
            if ((sc + 1) % c == 0)
                sc = 0, sr++;
            else
                sc++;
        }
        // string str = "";
    }
    for (int i = 0; i < vis.size(); i++)
    {
        for (int j = 0; j < vis[i].size(); j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << scorer(r, c, vis, grid) << nl;
    // for (int i = 0; i < s; i++)
    // {
    //     cout << vs[i].ss << " " << vs[i].ff << " ";
    //     cout << dir[i] << nl;
    // }
}
int main()
{
    clock_t begin = clock();
    YouCanDoIt;

    file;
    // write you code here

    int r, c, s;
    cin >> c >> r >> s;
    vector<ll> snakes(s);
    for (int i = 0; i < s; i++)
        cin >> snakes[i];
    vector<vector<ll>> grid(r, vector<ll>(c, 0));
    vector<vector<bool>> wormhole(r, vector<bool>(c, 0));
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
                wormhole[i][j] = 1;
            }
            else
            {
                grid[i][j] = stoll(s);
            }
            valPositions[grid[i][j]].insert({i, j});
        }
    }
    // helper(r, c, s, snakes, grid, wormhole, valPositions);
    solver(r, c, s, grid, snakes);
    return 0;
}