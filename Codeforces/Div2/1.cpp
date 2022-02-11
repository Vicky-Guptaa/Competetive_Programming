#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(string x, string y)
{
    int n = x.length();
    int m = y.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string txt, pat;
        cin >> txt >> pat;
        sort(txt.begin(), txt.end());
        int i;
        for (i = 0; i < txt.length(); i++)
        {
            int j;
            for (j = 0; j < pat.length(); j++)
            {
                if (pat[j] != txt[i + j])
                    break;
            }
            if (j == 3)
                break;
        }
        if (i == txt.length())
        {
            if (LCS(txt, pat) == 3)
            {
                int j;
                for (j = txt.length() - 1; j > 0; j++)
                {
                    if (txt[0] != txt[j])
                        break;
                }
                char a = txt[0];
                txt[0] = txt[j];
                txt[j] = a;
                cout << txt << "\n";
            }
            else
                cout << txt << "\n";
        }
        else
        {
            int j;
            for (j = i + 1; j < txt.length(); j++)
            {
                if (txt[i] != txt[j])
                    break;
            }
            char a = txt[i];
            txt[i] = txt[j];
            txt[j] = a;
            if (LCS(txt, pat) == 3)
            {
                int j;
                for (j = 1; j < txt.length(); j++)
                {
                    if (txt[i] != txt[j])
                        break;
                }
                char a = txt[0];
                txt[0] = txt[j];
                txt[j] = a;
                cout << txt << "\n";
            }
            else
                cout << txt << "\n";
        }
    }

    return 0;
}