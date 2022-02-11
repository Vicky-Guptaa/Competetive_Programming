#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void right_shift(int arr[], int n, int partition)
{
    reverse(arr, arr + n);
    reverse(arr, arr + partition);
    reverse(arr + partition, arr + n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        int log = log2(n);
        log = pow(2, log);
        log--;
        for (int i = n; i > log; i--)
        {
            cout << i << " ";
        }
        for (int i = 0; i <= log; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}