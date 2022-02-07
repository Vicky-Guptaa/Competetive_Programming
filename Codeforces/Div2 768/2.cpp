#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

int Solve(vector<int> arr, int n)
{
    int operation = 0;
    int dec = 1;
    int itr = 0;
    for (itr = n - 2; itr >= 0; itr--)
    {
        if (arr[itr] == arr[n - 1])
            dec++;
        else
        {
            itr -= dec;
            dec *= 2;
            operation++;
            itr++;
        }
    }
    return operation;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            umap[arr[i]]++;
        }
        if (umap.size() == 1)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << Solve(arr, n) << '\n';
        }
    }
    return 0;
}