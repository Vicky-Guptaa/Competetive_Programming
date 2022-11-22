#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> prime = {2, 3, 5, 7};
bool isPrime(char ch)
{
    for (auto x : prime)
    {
        if (ch - '0' == x)
        {
            return true;
        }
    }
    return false;
}
int helper(int s, int n, int k, int mL, string &str, vector<vector<long long>> &dp)
{
    if (s >= n)
    {
        if (k == 0 && s == n)
            return 1;
        return 0;
    }
    if (k == 0)
        return 0;

    if (dp[s][k] != -1)
        return dp[s][k];

    int ways = helper(s + 1, n, k, mL, str, dp);

    if (!isPrime(str[s]) && (s == n - 1 || (isPrime(str[s + 1]))))
    {
        ways += helper(s + mL, n, k - 1, mL, str, dp);
    }

    return dp[s][k] = ways;
}

int beautifulPartitions(string s, int k, int minLength)
{
    int n = s.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
    return helper(minLength, n, k, minLength, s, dp);
}

int main()
{
    cout << beautifulPartitions("231", 1, 2) << "\n";
    return 0;
}