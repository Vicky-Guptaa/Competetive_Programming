#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.90500000857922
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() > B.size())
    {
        return findMedianSortedArrays(B, A);
    }
    int low = 0, high = A.size();
    double res = 0;
    if (B.size() == 0)
    {
        if ((A.size()) % 2 == 0)
            return (float)((float)A[A.size() / 2] + (float)A[A.size() / 2 - 1]) / 2.0;
        else
            return (float)((float)A[A.size() / 2]);
    }
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = (A.size() + B.size() + 1) / 2 - mid1;
        int mid1_min = (mid1 == 0) ? INT_MIN : A[mid1 - 1];
        int mid2_min = (mid2 == 0) ? INT_MIN : B[mid2 - 1];
        int mid1_max = (mid1 >= A.size()) ? INT_MAX : A[mid1];
        int mid2_max = (mid2 >= B.size()) ? INT_MAX : B[mid2];
        if (mid2_min <= mid1_max && mid1_min <= mid2_max)
        {
            if ((A.size() + B.size()) % 2 == 0)
            {
                res += max(mid1_min, mid2_min);
                res += min(mid2_max, mid1_max);
                res /= 2;
            }
            else
            {
                res += max(mid2_min, mid1_min);
            }
            break;
        }
        else if (mid1_min > mid2_max)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a1(n), a2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }

    cout << findMedianSortedArrays(a1, a2);
    return 0;
}
/*
2 7
16 19
-46 -15 -9 -7 -2 24 40
*/