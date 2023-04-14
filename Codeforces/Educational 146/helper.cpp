#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool isValid(vector<int> &nums, int p, int mid)
{
    set<int> oset;
    for (int i = 0; i < nums.size(); i++)
        oset.insert(i);

    for (int i = 0; i < nums.size(); i++)
    {
        if (!oset.count(i))
            continue;
        auto tar = oset.lower_bound(mid + nums[i]);
        cout << i << "\n";
        if (tar != oset.end() && *tar > i && nums[*tar] == mid + nums[i])
        {
            cout << nums[*tar] << "-" << nums[i] << "\n";

            p--;
            oset.erase(*tar);
            oset.erase(i);
            if (p == 0)
                break;
            else
                continue;
        }
        if (tar == oset.begin())
            continue;
        tar = prev(tar);
        if (oset.count(*tar) && *tar > i && nums[*tar] < mid + nums[i])
        {
            cout << nums[*prev(tar)] << "--" << nums[i] << "\n";
            p--;
            oset.erase(*prev(tar));
            oset.erase(i);
            if (p == 0)
                break;
        }
    }
    return p == 0;
}

int minimizeMax(vector<int> &nums, int p)
{
    if (p == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int low = 0, high = 6, ans = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(nums, p, mid))
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
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    cout << minimizeMax(nums, 2) << "\n";
    return 0;
}