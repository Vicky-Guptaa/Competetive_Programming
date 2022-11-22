#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

long long totalCost(vector<int> &costs, int k, int candidates)
{
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    int left = 0, right = (int)costs.size() - 1;
    long long ans = 0;
    while (left <= right && k > 0)
    {
        while (pq1.size() < candidates && left <= right)
        {
            pq1.push(costs[left]);
            left++;
        }
        while (pq2.size() < candidates && left <= right)
        {
            pq2.push(costs[right]);
            right--;
        }
        if (pq1.top() <= pq2.top())
        {
            ans += pq1.top();
            pq1.pop();
        }
        else
        {
            ans += pq2.top();
            pq2.pop();
        }
        k--;
    }
    while (!pq1.empty() && !pq2.empty()&&k)
    {
        if (pq1.top() <= pq2.top())
        {
            ans += pq1.top();
            pq1.pop();
        }
        else
        {
            ans += pq2.top();
            pq2.pop();
        }
        k--;
    }
    while (!pq1.empty()&&k)
    {
        k--;
        ans += pq1.top();
        pq1.pop();
    }
    while (!pq2.empty()&&k)
    {
        k--;
        ans += pq2.top();
        pq2.pop();
    }
    return ans;
}

int main()
{
    vector<int> robot = {1, 2, 4, 1};
    cout << totalCost(robot, 3, 4) << "\n";
    return 0;
}