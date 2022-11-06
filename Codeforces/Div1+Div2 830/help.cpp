#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

long long helper(int i1, int i2, vector<int> &robot, vector<vector<int>> &factory, vector<vector<long long>> &dp)
{
    if (i2 == robot.size())
    {
        return 0;
    }
    if (i1 == factory.size())
    {
        return 1e15;
    }
    if (dp[i1][i2] != -1)
    {
        return dp[i1][i2];
    }

    long long sum = 1e15, cost = 0;

    for (int i = i2; i < robot.size() && i - i2 < factory[i1][1]; i++)
    {
        cost += abs(factory[i1][0] - robot[i]);
        sum = min(sum, cost + helper(i1 + 1, i + 1, robot, factory, dp));
    }
    return dp[i1][i2] = sum;
}

long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
{
    int n = robot.size(), m = factory.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));
    return helper(0, 0, robot, factory, dp);
}

int main()
{
    vector<int> robot = {1, -1};
    vector<vector<int>> factory = {{2, 2}, {6, 2}};
    cout << minimumTotalDistance(robot, factory) << "\n";
    return 0;
}