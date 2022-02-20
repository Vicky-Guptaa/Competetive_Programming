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
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];
                int Or = (arr[i] | arr[j]);
                if (sum >= Or)
                {
                    arr[i] = 0;
                    arr[j] = Or;
                    break;
                }
            }
        }
        int sum = 0;
        for (auto x : arr)
            sum += x;
        cout << sum << "\n";
    }
    return 0;
}