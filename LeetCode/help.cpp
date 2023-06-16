#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
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

struct fenwick
{
    // considering 1 based indexing
    vector<int> fenArr;
    int n;
    void init(int n)
    {
        this->n = n + 1;
        fenArr.resize(this->n, 0);
    }

    // Building the fenwick tree
    void add(int x, int y)
    {
        x++; // 1 based indexing
        while (x < n)
        {
            fenArr[x] += y;

            // adding the last set bit of x to x
            x += (x & (-x)); // gives the last set bit
        }
    }

    int sum(int x)
    {
        x++; // 1 based indxing
        int ans = 0;
        while (x > 0)
        {
            ans += fenArr[x];
            x -= (x & (-x));
        }
        return ans;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};
// here it is zero based indexing but internally in fenwick tree it is 1 based indexing

int main()
{
    vector<vector<int>> mat = {{1, 1}, {1, 0}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, 0}, {1, 0}, {0, 1}, {1, 1}};
    goodSubsetofBinaryMatrix(mat);
    return 0;
}