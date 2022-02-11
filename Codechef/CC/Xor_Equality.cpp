#include<iostream>
using namespace std;

long long int Fast_Power(long long int a,long long int b,long long int n=1000000007)
{
    long long int res=1;
    while(b>0)
    {
        if((b&1)!=0)
        {
            res=(res*a%n)%n;
        }
        a=(a%n*a%n)%n;
        b=b>>1;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int two_p=2<<(n-1);
        cout<<two_p/2<<endl;
        int count=0;
        for(int i=0;i<two_p;i++)
        {
            if((i^(i+1))==((i+2)^(i+3)))
            {
                count++;
                cout<<i<<" ";
            }
        }
        cout<<endl<<count<<endl<<endl;
    }
    return 0;
}