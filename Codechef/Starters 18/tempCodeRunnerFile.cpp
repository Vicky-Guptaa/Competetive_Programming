#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int count=0,j,i;
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(s1[j]<s2[j])
                {
                    count++;
                    count+=j-i;
                    i=j+1;
                    break;
                }
            }
            if(j==n)break;
        }
        cout<<count<<endl;
    }
	return 0;
}
