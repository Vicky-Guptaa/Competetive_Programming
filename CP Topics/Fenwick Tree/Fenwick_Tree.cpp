#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

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

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    // here it is zero based indexing but internally in fenwick tree it is 1 based indexing
    fenwick tree;
    tree.init(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        tree.add(i, v[i]);
    }
    cout << tree.sum(1, 6) << "\n";
    cout << "Check\n";
    return 0;
}