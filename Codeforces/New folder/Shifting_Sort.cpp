#include <iostream>
using namespace std;

void Grp_Check(int arr[], int n, int &i, int &j)
{
    for (i = 0; i < n - 1; i++)
        if (arr[i + 1] >= arr[i])
            break;
    for (j = n - 2; j > 0; j--)
        if (arr[j] > arr[j + 1])
            break;
    
    int Max=-2147483648;
    int Min=2147483647;
    for(int k=i;k<=j;k++)
    {
        Max=max(Max,arr[k]);
        Min=min(Min,arr[k]);
    }
    for(int k=0;k<=i;k++)
    {
        if(arr[k]>Min);
    }
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
            cin >> arr[i];
        int i, j;
    }
    return 0;
}