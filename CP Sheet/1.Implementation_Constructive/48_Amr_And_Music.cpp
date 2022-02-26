#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back({num, i + 1});
    }
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        k -= arr[i].first;
        if (k < 0)
        {
            break;
        }
        count++;
    }
    cout << count << "\n";
    for (int i = 0; i < count; i++)
    {
        cout << arr[i].second << " ";
    }
    cout << '\n';
    return 0;
}