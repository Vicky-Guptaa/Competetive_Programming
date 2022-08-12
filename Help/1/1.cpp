#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool isValid(vector<long long> &A, long long mid, int k)
{
    long long currRess = A[0] + mid;
    k--;
    for (int i = 0; i < A.size(); i++)
    {
        if (abs(A[i] - currRess) > mid)
        {
            currRess = A[i] + mid;
            k--;
            if (k < 0)
                return false;
        }
    }
    return true;
}

long long solve(int N, int K, vector<long long> A)
{
    sort(A.begin(), A.end());
    long long low = 0, high = 1e15, ans = 0;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isValid(A, mid, K))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<ll> A = {1, 7, 12};
    cout << solve(3, 1, A) << "\n";
    return 0;
}