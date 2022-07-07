#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<int> res = {arr[0]};
    for (int i = 1; i < n; i++)
    {
        if (res.back() < arr[i])
        {
            res.push_back(arr[i]);
        }
        else
        {
            int indx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[indx] = arr[i];
        }
    }
    cout << res.size() << "\n";
    return 0;
}