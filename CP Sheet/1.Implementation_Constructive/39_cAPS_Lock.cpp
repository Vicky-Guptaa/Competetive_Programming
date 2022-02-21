#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool ru = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (!isupper(s[i]))
        {
            ru = 0;
            break;
        }
    }
    if (ru)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!isupper(s[i]))
            {
                s[i] -= 32;
            }
            else if (isupper(s[i]))
            {
                s[i] += 32;
            }
        }
        cout << s << "\n";
    }
    else
        cout << s << "\n";
    return 0;
}