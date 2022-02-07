#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int N,K;
	    cin>>N>>K;
	    string str;
        cin>>str;
	    
	    int count=0,Max=-1;
	    for(int i=0;i<N;i++)
	    {
	        if(str[i]=='*')
	        {
	            count++;
	        }
	        else
	        {
	            count=0;
	        }
	        if(i+1<N&&str[i]=='*'&&str[i+1]=='*')
	        {
	            count++;i++;
	        }

	        Max=max(Max,count);
	    }
        if(Max>=K)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        cout<<Max<<" "<<count<<endl;
	}
	return 0;
}
