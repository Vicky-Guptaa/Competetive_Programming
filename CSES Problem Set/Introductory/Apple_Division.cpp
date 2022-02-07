#include<bits/stdc++.h>
using namespace std;

int main(){//WA
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long s1=0,s2=0;
    sort(arr,arr+n);
    n--;
    while(n>=0)
    {
        if(s1>s2)
        {
            s2+=(long long)arr[n];
        }
        else
        {
            s1+=(long long)arr[n];
        }
        n--;
    }
    cout<<abs(s1-s2)<<endl;
    return 0;
}