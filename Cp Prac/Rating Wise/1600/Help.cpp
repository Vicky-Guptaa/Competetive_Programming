#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
vector<int> findErrorNums(vector<int> &arr)
{
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
        {
            res.push_back(abs(arr[i]));
        }
        else
        {
            arr[arr[i] - 1] = -arr[arr[i] - 1];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            res.push_back(i + 1);
            break;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 3, 2}, brr = {2, 14, 10};
    brr = findErrorNums(arr);
    for (auto x : brr)
        cout << x << " ";

    return 0;
}