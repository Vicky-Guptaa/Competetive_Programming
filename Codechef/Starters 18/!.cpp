#include <iostream>
#include <stdlib.h>
using namespace std;

int func1(int n, string s1, string s2)
{
    int count = 0;
    while (s1.length())
    {
        if (s1.compare(s2) < 0)
        {
            count++;
        }
        s1 = s1.substr(1);
        s2 = s2.substr(1);
    }
    return count;
}

int func2(int n, string s1, string s2)
{
    int count = 0, j = 0,cnt=0;
    while (j < n)
    {
        bool check=true;
        cnt=0;
        while (s1[j] > s2[j]&&j<n)
            j++;
        while(s1[j]==s2[j]&&j++<n)cnt++;
        while (s1[j] < s2[j] && j < n)
        {
            check=false;
            count++;
            j++;
        }
        if(!check)
        count+=cnt;
    }
    return count;
}

int main()
{
    while (1)
    {
        int n;
        n = rand() % 10;
        cout << n << endl;
        string s1, s2;
        for (int i = 0; i < n; i++)
        {
            int n1 = rand() % 26, n2 = rand() % 26;
            s1 += ('a' + n1);
            s2 += ('a' + n2);
        }
        cout << s1 << " " << s2 << endl;
        int ans1 = func1(n, s1, s2);
        int ans2 = func2(n, s1, s2);
        if (ans1 == ans2)
        {
            cout << ans1 << " " << ans2 << " \nOk\n";
        }
        else
        {
            cout << ans1 << " " << ans2 << " \nWrong\n";
            break;
        }
    }
    return 0;
}
