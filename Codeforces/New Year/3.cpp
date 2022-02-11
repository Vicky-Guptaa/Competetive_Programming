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
        long double arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1 || n == 2)
        {
            cout << 0 << "\n";
            continue;
        }
        int min_oper = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                long double d = (arr[j] - arr[i]) / (j - i);
                int oper = 2;
                long double num = arr[i] - i * d;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    else if (abs(arr[k] - num - (k * d)) <= 1e-9)
                        oper++;
                }
                min_oper = max(oper, min_oper);
            }
        }
        cout << n - min_oper << "\n";
    }
    return 0;
}