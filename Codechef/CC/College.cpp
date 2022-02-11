#include<iostream>
using namespace std;
int Minimum=10000000;
int Min(int N,int E,int H,int A,int B,int C,int M)
{
    if(E<0||H<0)
    {
        return 0;
    }
    if((N!=0&&E==0&&H<3)||(N!=0&&H==0&&E<2)||(N!=0&&E==0&&H==0))
    {
        Minimum=-1;
        return 0;
    }
    if(N==0)
    {
        cout<<Minimum<<endl;
        Minimum=min(Minimum,M);
        return 0;
    }
    Min(N-1,E-2,H,A,B,C,M+A);
    Min(N-1,E,H-3,A,B,C,M+B);
    Min(N-1,E-1,H-1,A,B,C,M+C);
    return Minimum;
}

int main() {
    int n;
    cin>>n;
    while(n--)
    {
        int N,E,H,A,B,C;
        cin>>N>>E>>H>>A>>B>>C;
        int M=0;
    
        cout<<Min(N,E,H,A,B,C,M)<<endl;
    
        Minimum=10000000;
    }
    return 0;
}