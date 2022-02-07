#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << sum / 4 << " " << sum % 4 << "\n";
    }
    return 0;
}