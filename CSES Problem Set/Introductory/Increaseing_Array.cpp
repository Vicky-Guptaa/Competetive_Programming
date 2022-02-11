#include <bits/stdc++.h>
using namespace std;

long long int Min_Move(int arr[],int n)
{
    long long int min_move=0;
    int Max=0;
    for(int i=1;i<n;i++)
    {
        Max=max(Max,arr[i-1]);
        if(Max>arr[i])
        {
            min_move+=Max-arr[i];
        }
    }
    return min_move;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<Min_Move(arr,n)<<endl;
    return 0;
}