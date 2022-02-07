#include<bits/stdc++.h>
using namespace std;

void Permute(string str,string ans,set<string>&oset)
{
    if(str.length()==0)
    {
        oset.insert(ans);
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        Permute(str.substr(0,i)+str.substr(i+1),ans+c,oset);
    }
}

int main(){
    string str;
    cin>>str;
    set<string>oset;
    Permute(str,"",oset);
    cout<<oset.size()<<endl;
    for(auto x:oset)
    {
        cout<<x<<endl;
    }

    return 0;
}