#include <iostream>
using namespace std;

void Swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int i=0,j=n-1;
        
        //shuffle
        while(i<j)
        {
            if(arr[i]%2!=0)
            {
                Swap(arr,i,j);
                j--;
            }
            else i++;
        }
        if(arr[j]%2==0)j++;
        
        for(int i=1;i<n&&j<n;i+=2)
        {
            if(arr[i]%2==0)
            {
                Swap(arr,i,j);
                j++;
            }
        }
        cout<<endl;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
            sum+=(arr[i]+i+1)%2;
        }
        cout<<endl;
        cout<<sum<<endl;
    }
	return 0;
}
