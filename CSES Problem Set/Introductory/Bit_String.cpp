#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll ans=1;
    while(n--)
    {
        ans*=2;
        ans=ans%1000000007;
    }
    cout<<ans<<"\n";
    return 0;
}