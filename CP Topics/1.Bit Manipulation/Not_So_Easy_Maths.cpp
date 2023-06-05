#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <bits.h>
using namespace std;

typedef long long ll;

ll Number_Of_Number_Divisble_By_Prime_Less_Than_20(ll n)
{
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int arrlen = 8;
    int total_subsets = (1 << 8) - 1;
    ll result = 0;
    for (int i = 1; i <= total_subsets; i++)
    {
        int num = i;
        int setbit = __builtin_popcount(num);
        int prod = 1;
        for (int j = 0; j < arrlen; j++)
        {
            if (num & 1)
            {
                prod *= arr[j];
            }
            num >>= 1;
            if (num == 0)
                break;
        }
        if (setbit & 1)
        {
            result += n / prod;
        }
        else
        {
            result -= n / prod;
        }
    }
    return result;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << Number_Of_Number_Divisble_By_Prime_Less_Than_20(n) << "\n";
    }

    return 0;
}