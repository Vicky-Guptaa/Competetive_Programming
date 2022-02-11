#include<bits/stdc++.h>
using namespace std;

void Tower_Of_Hanoi(int n,int s,int h,int d)
{
    if(n<=0)return;
    Tower_Of_Hanoi(n-1,s,d,h);
    cout<<s<<" "<<d<<endl;
    Tower_Of_Hanoi(n-1,h,s,d);
}

int main(){
    long long int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    Tower_Of_Hanoi(n,1,2,3);
    return 0;
}