#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string arr[3];
	    for(int i=0;i<3;i++)
	    {
	        cin>>arr[i];
	    }
	    char carr[3][3];
	    int xc=0,oc=0,uc=0;
	    for(int i=0;i<3;i++)
	    {
	        string str=arr[i];
	        for(int j=0;j<3;j++)
	        {
	            carr[i][j]=str[j];
	            if(str[j]=='X')xc++;
	            if(str[j]=='O')oc++;
	            if(str[j]=='_')uc++;
	        }
	    }
	    
	    int xwin=0,owin=0;
	    for(int i=0;i<3;i++)
	    {
	        int oh=0,xh=0,xv=0,ov=0;
	        for(int j=0;j<3;j++)
	        {
	            if(carr[i][j]=='X')xh++;
	            if(carr[i][j]=='O')oh++;
	            if(carr[j][i]=='X')xv++;
	            if(carr[j][i]=='O')ov++;
	            
	        }
	        if(oh==3)owin++;
	        if(xh==3)xwin++;
	        if(xv==3)xwin++;
	        if(ov==3)owin++;
	    }
	    if(carr[0][0]==carr[1][1]&&carr[2][2]==carr[1][1])xwin++;
	    if(carr[0][2]==carr[1][1]&&carr[2][0]==carr[1][1])owin++;
	    owin=xwin+owin;
	    if(owin==1)cout<<3<<endl;
	    else if(owin>1)cout<<2<<endl;
	    else cout<<1<<endl;
	}
	return 0;
}
