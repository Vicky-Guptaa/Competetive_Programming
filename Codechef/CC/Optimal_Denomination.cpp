#include<iostream>
using namespace std;

bool isValid(long long int arr[],long long int n,long long int k)
{
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]%k!=0)
        {
            return 0;
        }
    }
    return 1;
}

long long int MoneyCount(long long int arr[],long long int n,long long int answer)
{
    long long int count=0;
    for(long long int i=0;i<n;i++)
    {
        count+=arr[i]/answer;
    }
    return count;
}

long long int Optimal_Denomination(long long int arr[],long long int n)
{
    long long int low=1,high=1;
    for(long long int i=0;i<n;i++)
    {
        high=max(high,arr[i]);
    }
    long long int answer=1;
    while(high>=low)
    {
        long long int mid=low+(high-low)/2;
        if(isValid(arr,n,mid))
        {
            answer=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return answer;
}

long long int Modification(long long int arr[],long long int n)
{
    long long int low=0,high=0;
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]>arr[high])
        high=i;
        if(arr[i]<arr[low])
        low=i;
    }

    long long int count=0,ind;
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]%arr[low]!=0)
        {
            ind=i;
            count++;
        }
    }
    if(count==1)
    {
        arr[ind]=arr[low];
        return MoneyCount(arr,n,arr[low]);
    }
    else if(count==0)
    {
        arr[high]=arr[low];
        return MoneyCount(arr,n,arr[low]);
    }
    long long int div=arr[ind],key;
    for(long long int i=arr[low]-1;i>=1;i--)
    {
        bool chk=1;
        for(long long int j=0;j<n;j++)
        {
            if(j!=low&&arr[j]%i!=0)
            {
                chk=0;
                break;
            }
        }
        if(chk&&i>1)
        {
            arr[low]=i;
            return MoneyCount(arr,n,i);
        }
        if(chk&&i==1)
        {
            arr[high]=1;
            return MoneyCount(arr,n,i);
        }
    }
    return MoneyCount(arr,n,Optimal_Denomination(arr,n));
}


int main(){
   int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long int sal[n];
        for( int i=0;i<n;i++)
        {
            cin>>sal[i];
        }       
        cout<<Modification(sal,n)<<endl;
    }
    return 0;
}