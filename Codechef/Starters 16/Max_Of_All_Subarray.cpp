#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long Merge(int arr[], int s, int mid, int n)
{
    long long sum=0;
    int p = mid - s + 1, q = n - mid;
    int a1[p], a2[q],Max=0;
    for (int i = 0; i < p; i++)
    {
        a1[i] = arr[s + i];
        Max=max(Max,a1[i]);

    }
    sum+=Max;
    Max=0;
    for (int i = 0; i < q; i++)
    {
        a2[i] = arr[mid + i + 1];
        Max=max(Max,a2[i]);
    }
    sum+=Max;
    int x = 0, y = 0, z = s;
    while (x < p && y < q)
    {
        if (a1[x] > a2[y])
        {
            arr[z] = a2[y];
            z++;
            y++;
        }
        else
        {
            arr[z] = a1[x];
            z++;
            x++;
        }
    }
    while (x < p)
    {
        arr[z] = a1[x];
        z++;
        x++;
    }
    while (y < q)
    {
        arr[z] = a2[y];
        z++;
        y++;
    }
    return sum;
}

long long Devide_Conque(int arr[], int s, int n)
{
    if (s >= n)
        return arr[s];
    int mid = s + (n - s) / 2;
    long long lsum = Devide_Conque(arr, s, mid);
    long long rsum = Devide_Conque(arr, mid + 1, n);
    return Merge(arr, s, mid, n) + lsum + rsum;
}

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
        cout << Devide_Conque(arr, 0, n - 1) << endl;
    }
    return 0;
}