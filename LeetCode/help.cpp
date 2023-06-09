#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int maxScore(vector<int> &cardPoints, int k)
{
    int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int n = cardPoints.size();
    int wsize = n - k;
    int maxScore = 0, wsum = 0;
    for (int i = 0; i < n; i++)
    {
        wsum += cardPoints[i];
        if (i > wsize)
            wsum -= cardPoints[i - wsize];
        if (i + 1 >= wsize)
        {
            maxScore = max(maxScore, sum - wsum);
        }
    }
    return maxScore;
}
int main()
{
    vector<int> arr = {9, 7, 7, 9, 7, 7, 9};
    cout << maxScore(arr, 7) << "\n";
    return 0;
}