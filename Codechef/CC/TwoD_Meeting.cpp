#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }
        
        unordered_map<int,int>umap;
        int Max=0;
        for(int i=0;i<n;i++)
        {
            if(arr1[i]==arr2[i])
            {
                umap[arr1[i]]++;
                Max=max(Max,umap[arr1[i]]);
            }
        }
        
    }
    return 0;
}