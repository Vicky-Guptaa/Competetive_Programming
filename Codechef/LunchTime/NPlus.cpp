#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if(n==1)
        {
            cout<<"1 1"<<endl;
        }
        else 
        {
            vector<long long>ans;
            long long total_sum=n*(n+1)/2;
            long long power=pow(2,n);
            for(int i=1;i<n;i++)
            {
                power-=i;
                ans.push_back(i);
            }
            if((float)power/2>n)
            {
                ans.push_back(n-1);
                ans.push_back(power-n+1);
            }
            else
            {
                ans.push_back(n);
                ans.push_back(power-n);
            }
            sort(ans.begin(),ans.end());
            for(auto x:ans)cout<<x<<" ";
            cout<<"\n";
        }

    }
    return 0;
}