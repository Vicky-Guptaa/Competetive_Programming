#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    string news;
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' ||
              s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' || s[i] == 'y' || s[i] == 'Y'))
            news += s[i];
    }
    if (news.length() == 0)
        cout << "\n";
    else
    {
        string res;
        for (int i = 0; i < news.length(); i++)
        {
            if (isupper(news[i]))
            {
                news[i] += 32;
            }
            res += '.';
            res += news[i];
        }
        cout << res << "\n";
    }
    return 0;
}