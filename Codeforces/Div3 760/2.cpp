#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string bigram[n - 2];
        for (int i = 0; i < n - 2; i++)
            cin >> bigram[i];
        if (n - 2 == 1)
        {
            cout << "b" << bigram[0] << "\n";
            continue;
        }
        int i;
        for (i = 1; i < n - 2; i++)
        {
            string s1 = bigram[i - 1], s2 = bigram[i];
            if (s1[1] != s2[0])
            {
                break;
            }
        }
        if (i == n - 2)
        {
            string answer;
            for (int j = 0; j < n - 3; j++)
            {
                string s1 = bigram[j];
                answer += s1[0];
            }
            string s1 = bigram[n - 3];
            answer += s1 + s1[1];
            cout << answer << "\n";
            continue;
        }
        string answer;
        for (int j = 0; j < i - 1; j++)
        {
            string s1 = bigram[j];
            answer += s1[0];
        }
        answer += bigram[i - 1];
        if (i < n - 2)
            answer += bigram[i++];
        for (i; i < n - 2; i++)
        {
            string s1 = bigram[i];
            answer += s1[1];
        }
        cout << answer << "\n";
    }
    return 0;
}