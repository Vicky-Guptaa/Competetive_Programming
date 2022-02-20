#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> index;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                index.push_back(i);
            }
        }
        int count = 0;
        for (int i = 0; i < index.size(); i++)
        {
            if (i + 1 < index.size() && index[i] + 2 == index[i + 1])
            {
                arr[index[i] + 1] = max(arr[index[i]], arr[index[i] + 2]);
                count++;
                i++;
            }
            else
            {
                if (arr[index[i] - 1] < arr[index[i]] && arr[index[i]] > arr[index[i] + 1])
                {
                    arr[index[i]] = max(arr[index[i] + 1], arr[index[i] - 1]);
                    count++;
                }
            }
        }
        cout << count << "\n";
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}