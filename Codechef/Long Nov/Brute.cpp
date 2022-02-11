#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int func2(int Max,int arr[],int n)
{
    int i;
    for (i = 0; i <= Max; i++)
    {
        int Xor = 0;
        for (int j = 0; j < n; j++)
        {
            Xor ^= (arr[j] + i);
        }
        if (Xor == 0)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n],Max=0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            Max = max(Max, arr[i]);
        }
        cout<<func2(Max,arr,n)<<endl;
    }
    return 0;
}