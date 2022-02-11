#include<iostream>
#include<vector>
using namespace std;

int main(){
	long long t;
	cin>>t;
	while(t--)
	{
	    long long t,p;
	    cin>>t>>p;
	    long long tarr[t],parr[p];
	    for(long long i=0;i<t;i++)
	    {
	        cin>>tarr[i];
	    }
	    for(long long i=0;i<p;i++)
	    {
	        cin>>parr[i];
	    }

	    vector<long long>lt(t,-1),rt(t,-1);
        lt[0]=0;
	    long long c1=0,c2=0;
        bool chk1=false,chk2=false;
        for(long long i=0;i<t;i++)
	    {
            if(tarr[i]==1)
            {
                chk1=true;
                c1=0;
            }
            if(i==0)c1++;
            if(chk1&&i>0)lt[i]=c1++;

            if(tarr[t-i-1]==2)
            {
                chk2=true;
                c2=0;
            }
            if(chk2)rt[t-1-i]=c2++;
	    }

	    for(long long i=0;i<p;i++)
	    { 
            long long min1=lt[parr[i]-1];
            long long min2=rt[parr[i]-1];
            if(min1>=0&&min2>=0)cout<<min(min1,min2)<<" ";
            else if(min1==-1&&min2==-1)cout<<-1<<" ";
            else cout<<max(min1,min2)<<" ";
	    }
	    cout<<endl;
	}
    return 0;
}