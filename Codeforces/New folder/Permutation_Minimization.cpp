#include<iostream>
#include<deque>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        deque<int>dq;
        dq.push_front(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(dq.front()>arr[i])
                dq.push_front(arr[i]);
            
            else 
                dq.push_back(arr[i]);
        }
        while(!dq.empty())
        {
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}