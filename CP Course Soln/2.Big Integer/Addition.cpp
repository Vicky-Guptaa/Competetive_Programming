#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

string Add(string s1, string s2)
{
    string answer;
    int n = s1.length(), m = s2.length();
    int minlen = min(n, m), carry = 0;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int it = 0; it < minlen; it++)
    {
        int n1 = (s1[it] - '0');
        int n2 = (s2[it] - '0');
        int res = n1 + n2 + carry;
        carry = res / 10;
        int remain = res % 10;
        answer += to_string(remain);
    }

    if (n != m)
    {
        string left = (n > m) ? s1 : s2;
        int maxlen = max(n, m);
        for (int it = minlen; it < maxlen; it++)
        {
            int n1 = (left[it] - '0');
            int res = n1 + carry;
            carry = res / 10;
            int remain = res % 10;
            answer += to_string(remain);
        }
    }

    if (carry != 0)
    {
        answer += to_string(carry);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string res = Add(s1, s2);
    cout << res << "\n";
    return 0;
}