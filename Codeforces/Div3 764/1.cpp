#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n], Max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        Max = arr[n - 1];
        int oper = 0;
        int incre = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == Max)
                continue;
            int bada = Max - arr[i] - incre;
            incre += bada;
            oper += bada;
        }
        cout << oper << "\n";
    }
    return 0;
}