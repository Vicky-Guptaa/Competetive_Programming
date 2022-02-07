#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--)
    {
        int N;
        cin>>N;
        int d=log2(N);
        d=pow(2,d+1);
        int Max=0;
        for(int i=d-1;i>=N/2;i--)
        {
           for(int j=d-1;j>=N/2;j--)
           {
                if((i^j)==N)
                {
                    Max=max(Max,i*j);
                }
           }
        }
        cout<<Max<<endl;   
    }
    return 0;
}