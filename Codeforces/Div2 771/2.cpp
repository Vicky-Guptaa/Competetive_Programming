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
        for (int j = 0; j < n; j++)
        {
            bool isSwap = 0;
            for (int i = 1; i < n; i++)
            {
                if (arr[i - 1] > arr[i] && (arr[i] + arr[i - 1]) & 1)
                {
                    isSwap = true;
                    swap(arr[i], arr[i - 1]);
                }
            }
            if (!isSwap)
                break;
        }
        bool isSort = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                isSort = false;
                break;
            }
        }
        if (isSort)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}