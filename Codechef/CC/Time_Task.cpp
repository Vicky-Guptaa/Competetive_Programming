#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int N,M,K;
        cin>>N>>M>>K;
        int sub[N],tim[N];
        for(int i=0;i<N;i++)cin>>sub[i];
        for(int j=0;j<N;j++)cin>>tim[j];
        map<int,vector<int>>map;
        for(int i=0;i<N;i++)
        {
            map[tim[i]].push_back(sub[i]);
        }
        for(auto x:map)
        {
            sort(x.second.begin(),x.second.end());
        }
        vector<int>ktim(M,0);
        
        while(true)
        {
            int count=0;
            for(auto x:map)
            {
                vector<int>res=x.second;
                for(int i=0;i<res.size();i++)
                {
                    
                }
            }
        }

    }
    return 0;
}