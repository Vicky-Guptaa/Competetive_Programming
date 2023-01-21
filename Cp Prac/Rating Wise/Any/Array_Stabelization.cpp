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

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
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

// Code

class SegmentTree
{
    vector<int> arr, tree;

public:
    SegmentTree(vector<int> &nums)
    {
        int n = nums.size();
        arr = nums;
        tree.resize(4 * n, 0);
        initialize(0, 0, n - 1);
    }

    int combine(int a, int b)
    {
        return gcd(a, b);
    }
    void initialize(int indx, int strt, int end)
    {
        if (strt > end)
            return;

        if (strt == end)
        {
            tree[indx] = arr[strt];
            return;
        }
        int mid = (strt + end) / 2;
        initialize(indx * 2 + 1, strt, mid);
        initialize(indx * 2 + 2, mid + 1, end);
        tree[indx] = combine(tree[indx * 2 + 1], tree[indx * 2 + 2]);
    }

    void update(int indx, int strt, int end, int pos, int val)
    {
        if (strt > pos || end < pos)
            return;
        if (strt == end)
        {
            tree[indx] = val;
            arr[strt] = val;
            return;
        }
        int mid = (strt + end) / 2;
        update(indx * 2 + 1, strt, mid, pos, val);
        update(indx * 2 + 2, mid + 1, end, pos, val);
        tree[indx] = combine(tree[indx * 2 + 1], tree[indx * 2 + 2]);
    }

    void update(int index, int val)
    {
        update(0, 0, (int)arr.size() - 1, index, val);
    }

    int gcdRange(int indx, int strt, int end, int left, int right)
    {
        if (strt > right || end < left)
            return 0;

        if (strt >= left && end <= right)
        {
            return tree[indx];
        }

        int mid = (strt + end) / 2;
        int lleft = gcdRange(indx * 2 + 1, strt, mid, left, right);
        int rright = gcdRange(indx * 2 + 2, mid + 1, end, left, right);

        return combine(lleft, rright);
    }

    int gcdRange(int left, int right)
    {
        return gcdRange(0, 0, (int)arr.size() - 1, left, right);
    }
};

bool isAllSame(vi &arr)
{
    fl(i, 1, arr.size())
    {
        if (arr[i] != arr[i - 1])
            return false;
    }
    return true;
}

bool isValid(int mid, SegmentTree &tree, int n)
{
    vi temp(n, 0);
    fl(i, 0, n - mid)
    {
        temp[i] = tree.gcdRange(i, i + mid);
    }
    fl(i, n - mid, n)
    {
        temp[i] = gcd(tree.gcdRange(i, n - 1), tree.gcdRange(0, i - (n - mid)));
    }
    return isAllSame(temp);
}

void solve()
{
    ll n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    int low = 0, high = n, ans = 0;
    SegmentTree tree(arr);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isValid(mid, tree, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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
