#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int findLongestPalindromicString(string text)
{
    int N = text.size();
    if (N == 0)
        return 0;
    N = 2 * N + 1; // Position count
    int L[N];      // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1;   // centerPosition
    int R = 2;   // centerRightPosition
    int i = 0;   // currentRightPosition
    int iMirror; // currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    for (i = 2; i < N; i++)
    {

        iMirror = 2 * C - i;
        L[i] = 0;
        diff = R - i;

        if (diff > 0)
            L[i] = min(L[iMirror], diff);

        while (((i + L[i]) < N && (i - L[i]) > 0) &&
               (((i + L[i] + 1) % 2 == 0) ||
                (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2])))
        {
            L[i]++;
        }

        if (L[i] > maxLPSLength)
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }
    // printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
    return end - start + 1;
}

int helper(int s, int e, vector<int> &arr, vector<vector<int>> &dp)
{
    if (s >= e)
        return 0;

    if (dp[s][e] != -1)
        return dp[s][e];

    if (arr[s] == arr[e])
    {
        return dp[s][e] = helper(s + 1, e - 1, arr, dp);
    }
    else
    {
        return dp[s][e] = 1 + min(helper(s + 1, e, arr, dp), helper(s, e - 1, arr, dp));
    }
}

int MNPS(int N, vector<string> Arr)
{
    vector<int> newArr;
    for (int i = 0; i < N; i++)
    {
        newArr.push_back(findLongestPalindromicString(Arr[i]));
    }
    vector<vector<int>> dp(N, vector<int>(N, -1));
    int ans = helper(0, N - 1, newArr, dp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> srr(n);
    for (auto &x : srr)
        cin >> x;
    cout << MNPS(n, srr) << "\n";
    return 0;
}