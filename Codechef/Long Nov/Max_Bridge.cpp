#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        for(int i=2;i<=n;i++)
        {
            graph[i][i-1]=1;
        }
        int count=e-n+1;
        while(count>0)
        {
            for(int j=3;j<=n&&count>0;j++)
            {
                for(int i=j-2;i>=1&&count>0;i--)
                {
                    if(graph[j][i]==0)
                    {
                        graph[j][i]=1;
                        count--;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(graph[j][i]==1)
                {
                    cout<<j<<" "<<i<<endl;
                }
            }
        }
    }
	return 0;
}
