#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int minimumSum(string s)
{
    int n = s.size();
    vector<int> indx;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (s[i] != '?' || s[n - 1 - i] != '?')
        {
            if (s[i] != '?' && s[n - 1 - i] != '?' && (s[i] != s[n - 1 - i]))
                return -1;
            if (s[i] == '?')
                s[i] = s[n - 1 - i];
            if (s[n - 1 - i] == '?')
                s[n - 1 - i] = s[i];
        }
    }
    char start;

    for (int i = 0; i < (n) / 2; i++)
    {
        if (s[i] != '?')
        {
            start = s[i];
            break;
        }
    }
    int score = 0;
    for (int i = 0; i < (n) / 2; i++)
    {
        if (s[i] != '?')
        {
            start = s[i];
            score += (i > 0) ? abs(s[i] - s[i - 1]) : 0;
            continue;
        }
        s[i] = start;
        s[n - 1 - i] = start;
        score += (i > 0) ? abs(s[i] - s[i - 1]) : 0;
    }
    cout << s << "\n";
    return score * 2;
}
int main()
{
    string s = "????k??n??????";
    cout << minimumSum(s) << "\n";
    return 0;
}