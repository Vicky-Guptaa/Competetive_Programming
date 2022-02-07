#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n;
        e=pow(2,n);
        map<int,int>omp;
        for(int i=0;i<e;i++)
        {
            int num;
            cin>>num;
            omp[num]++;
        }
        
    }
    return 0;
}