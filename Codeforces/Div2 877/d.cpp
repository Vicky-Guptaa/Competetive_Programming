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

struct node
{
    ll val;
    ll cnt;
    // can add more if required or remove
    node(ll v = 0, ll c = 0)
    {
        val = v;
        cnt = c;
    }
};

class segTree
{
public:
    vector<node> segArr;
    vector<ll> narr;

    segTree(vector<ll> arr)
    {
        narr = arr;
        int arrSize = arr.size();
        narr = arr;
        /*
 we are constructing tree in form of array linearly therefore
we have to make 4*n size array for n size given array
*/
        segArr.resize(4 * arrSize);
        constructSegTree(0, 0, arrSize - 1);
    }

    // here you can change the combine logic according to questions
    node Combine(node &left, node &right)
    {
        return node(left.val + right.val, 0);
    }

    void constructSegTree(int index, int startIndx, int endIndx)
    {
        if (startIndx == endIndx)
        {
            // Leaf Logic
            segArr[index] = node(narr[startIndx], 0);
            return;
        }
        int midIndx = startIndx + (endIndx - startIndx) / 2;

        constructSegTree(2 * index + 1, startIndx, midIndx);
        constructSegTree(2 * index + 2, midIndx + 1, endIndx);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }
    node getQuery(int index, int startIndx, int endIndx, int lquery, int rquery)
    {
        // no overlap
        if (startIndx > rquery || lquery > endIndx)
            return node(0, 0);

        // complete overlap
        if (startIndx >= lquery && endIndx <= rquery)
            return segArr[index];

        // partial overlap
        int midIndx = startIndx + (endIndx - startIndx) / 2;
        node left = getQuery(index * 2 + 1, startIndx, midIndx, lquery, rquery);
        node right = getQuery(index * 2 + 2, midIndx + 1, endIndx, lquery, rquery);

        return Combine(left, right);
    }

    void updateQuery(int index, int startIndx, int endIndx, int position, int val)
    {
        if (position < startIndx || position > endIndx)
            return;

        if (startIndx == endIndx)
        {
            // Leaf Condition
            segArr[index] = node(val, 0);
            narr[startIndx] = val;
            return;
        }

        int midIndx = startIndx + (endIndx - startIndx) / 2;
        updateQuery(2 * index + 1, startIndx, midIndx, position, val);
        updateQuery(2 * index + 2, midIndx + 1, endIndx, position, val);
        segArr[index] = Combine(segArr[2 * index + 1], segArr[2 * index + 2]);
    }

    // Use To Get The result of the queries
    void updateQuery(int postion, int value)
    {
        updateQuery(0, 0, (int)narr.size() - 1, postion, value);
    }

    node getQuery(int lquery, int rquery)
    {
        return getQuery(0, 0, (int)narr.size() - 1, lquery, rquery);
    }
};
// use 0 based indexing while calling the update and query func

// Code
void solve()
{
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n & 1)
    {
        while (m--)
        {
            ll num;
            cin >> num;
            pn
        }
        return;
    }
    set<int> lset, rset;
    fl(i, 1, n)
    {
        if (s[i] == s[i - 1] && s[i] == '(')
            lset.insert(i);
        if (s[i] == s[i - 1] && s[i] == ')')
            rset.insert(i);
    }

    while (m--)
    {
        ll num;
        cin >> num;
        num--;

        if (lset.count(num))
            lset.erase(num);
        if (lset.count(num + 1))
            lset.erase(num + 1);
        if (rset.count(num))
            rset.erase(num);
        if (rset.count(num + 1))
            rset.erase(num + 1);

        if (s[num] == '(')
            s[num] = ')';
        else
            s[num] = '(';

        if (num > 0 && s[num] == s[num - 1] && s[num] == '(')
            lset.insert(num);
        if (num < n - 1 && s[num] == s[num + 1] && s[num] == '(')
            lset.insert(num + 1);

        if (num > 0 && s[num] == s[num - 1] && s[num] == ')')
            rset.insert(num);
        if (num < n - 1 && s[num] == s[num + 1] && s[num] == ')')
            rset.insert(num + 1);

        if (s.front() == ')' || s.back() == '(')
        {
            pn continue;
        }
        if (s.front() == '(' && lset.size() == rset.size() && lset.size() == 0)
        {
            py continue;
        }
        if (s.front() == '(' && (lset.size() == 0 || rset.size() == 0))
        {
            pn continue;
        }
        if (*lset.begin() < *rset.begin() && *lset.rbegin() < *rset.rbegin())
        {
            py continue;
        }
        else
        {
            pn continue;
        }
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
