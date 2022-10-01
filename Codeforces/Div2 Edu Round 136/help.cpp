#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;
int processArray(vector<int> &array)
{
    ll ans = 0, diff = 0;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] >= array[i - 1])
        {
            diff += array[i] - array[i - 1];
        }
        else
            diff = 0;
        ans = max(diff, ans);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 7, 46, 42, 42, 141, 56, 34, 36, 381, 681, 6, 4, 9};
    cout << processArray(arr) << "\n";
    return 0;
}