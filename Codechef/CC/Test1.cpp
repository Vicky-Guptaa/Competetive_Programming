#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int N,M;
	    cin>>N>>M;
	    int X,Y;
	    cin>>X>>Y;
	    string sarr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>sarr[i];
	    }
	    
	    string ans;
	    for(int i=0;i<N;i++)
	    {
	        int F=0,P=0,U=0;
	        string str=sarr[i];
	        for(int j=0;j<M;j++)
	        {
	            if(str[j]=='F')F++;
	            else if(str[j]=='U')U++;
	            else if(str[j]=='P')P++;
	        }
	        if(F>=X)
	        {
	            ans+='1';
	        }
	        else if(((F-1)>=X)&&(P>=Y))
	        {
	            ans+='1';
	        }
	        else
	        {
	            ans+='0';
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
