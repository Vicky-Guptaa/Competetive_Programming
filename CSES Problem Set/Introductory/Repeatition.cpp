#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int count = 1;
    int Max = 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == str[i])
            count++;
        else
            count = 1;
        Max = max(count, Max);
    }
    Max = max(count, Max);
    cout << Max << endl;
    return 0;
}