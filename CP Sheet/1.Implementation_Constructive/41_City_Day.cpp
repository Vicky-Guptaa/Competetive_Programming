#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool isTrue = 1;
        for (int j = i - 1; j >= max(0, i - x); j--)
        {
            if (arr[i] > arr[j])
            {
                isTrue = false;
                break;
            }
        }
        if (!isTrue)
            continue;
        for (int j = i + 1; j < min(i + y + 1, n); j++)
        {
            if (arr[i] > arr[j])
            {
                isTrue = false;
                break;
            }
        }
        if (!isTrue)
            continue;
        cout << i + 1 << "\n";
        return 0;
    }
    cout << n << "\n";
    return 0;
}