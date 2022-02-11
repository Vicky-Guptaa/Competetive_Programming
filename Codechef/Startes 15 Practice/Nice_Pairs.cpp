#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Another_Way(string str,int n)
{
    unordered_map<int,int>umap1,umap2;
    for(int i=0;i<n;i++)
    {
        umap1[i+stoi(str.substr(i,1))]++;
        umap2[i-stoi(str.substr(i,1))]++;
    }
    int count=0;
    for(auto x:umap1)
    {
        if(x.second>1)
        {
            count+=x.second*(x.second-1)/2;
        }
    }
    for(auto x:umap2)
    {
        if(x.second>1)
        {
            count+=x.second*(x.second-1)/2;
        }
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        // int count=0;
        // unordered_map<int,int>umap;
        // for(int i=0;i<n;i++)
        // {
        //     str[]
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<9;j++)
        //     {
        //         if(j-i==abs(str[j]-str[i]))count++;
        //     }
        // }
        // cout<<count<<endl;
        cout<<Another_Way(str,n)<<endl;
    }
	return 0;
}
