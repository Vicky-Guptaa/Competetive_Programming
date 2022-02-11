#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            int freq[] = {0};
            int tck = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[j] <= n)
                {
                    freq[arr[j]]++;
                    while (tck <= n && freq[tck] > 0)
                        tck++;
                    map[tck]++;
                }
            }
        }
        for (auto x : map)
        {
            k -= x.second;
            if (k <= 0)
            {
                cout << x.first << endl;
                break;
            }
        }
    }
    return 0;
}
