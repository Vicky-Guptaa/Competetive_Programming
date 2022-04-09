#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    vector<string> names;
    string user;
    int n;
    cout << "Enter number of Users : ";
    cin >> n;
    // cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> user;
        names.push_back(user);
    }
    // cout << "L->" << s.length() << endl;

    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
    }
    int c = 0, min = 99999999;
    string s;
    string res;
    for (int i = 0; i < names.size(); i++)
    {
        int l = names[i].length();
        // cout<<"L->"<<l<<endl;
        if (l < min)
        {
            min = l;
            s = names[i];
        }
    }
    for (int i = 0; i < min; i++)
    {
        for (int j = 0; j < names.size(); j++)
        {
            if (names[j][i] != s[i])
                res = s.substr(0, c);
        }
        c++;
    }
    cout << res << endl;
    return 0;
}