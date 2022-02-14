#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// void Reverse(int arr[], int i, int e)
// {
//     if (i == e)
//         return;
//     for (int i = 0; i < n; i++)
//     {
//     }
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int l = 0, r = 0;
        bool isFind = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                int end = 0;
                for (int j = i; j < n; j++)
                {
                    if (arr[j] == i + 1)
                    {
                        end = j;
                        break;
                    }
                }
                reverse(arr.begin() + i, arr.begin() + end + 1);
                break;
            }
        }
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}