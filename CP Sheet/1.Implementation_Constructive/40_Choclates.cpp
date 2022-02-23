#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, arr + n);
    int max_sum = 0;
    int iter = 1;
    while (iter < n)
    {
        int sum = 0;
        while (iter < n)
        {
            if (arr[iter - 1] > arr[iter])
            {
                sum += arr[iter];
            }
            else
            {
            }
        }
    }
    return 0;
}