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
    vector<int> arr = {5, 4, 3, 2, 1, 1, 1};
    int n = arr.size();
    fenwick tree;
    tree.init(arr.size());
    vector<pair<int, int>> prr;
    for (int i = 0; i < arr.size(); i++)
        prr.push_back({arr[i], i});
    sort(prr.begin(), prr.end());

    int inversionCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        tree.add(prr[i].second, 1);
        // n-1 bcoz hrere in this main function it is 0 based indexing
        inversionCount += tree.sum(prr[i].second + 1, n - 1);
    }
    cout << inversionCount << "\n";

    return 0;
}