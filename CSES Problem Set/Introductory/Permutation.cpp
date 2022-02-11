#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int j=2;
    int k=1;   
    /*
    Here We Have Start Adding Number From 2 To Largest Even Bcoz 
    If We Start Storing From 1 Then For The Test Case 4 We Get 
    1 3 2 4 Which Shows No Solution But It Has Solution Which Is 
    2 4 1 3 By Storing Even First The Diffrence Will Remain Greater
    Than 1.Thats Why Storing Even NUmber is Better Choice. If We Store 
    Odd First Then Only The 4 th Test Case Show Wrong Answer Other Test
    Case Will Run Without Any Wrong Answer.
    */
    int i;
    for(i=0;j<=n;i++)
    {
        arr[i]=j;
        j+=2;
    }
    for(i;k<=n;i++)
    {
        arr[i]=k;
        k+=2;
    }
    for(int i=1;i<n;i++)
    {
        if(abs(arr[i-1]-arr[i])==1)
        {
            cout<<"NO SOLUTION"<<endl;
            return 0; 
        }
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}