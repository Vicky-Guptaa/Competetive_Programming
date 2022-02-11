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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long answer = 1, sum = 0;
        int Max = 0;
        for (int i = 0; i < n; i++)
        {

            int temp = arr[i];
            while (temp % 2 == 0)
            {
                answer *= 2;
                temp /= 2;
            }
            arr[i] = temp;
            Max = max(Max, arr[i]);
            sum += arr[i];
        }
        sum -= Max;
        sum += answer * Max;
        cout << sum << "\n";
    }
    return 0;
}