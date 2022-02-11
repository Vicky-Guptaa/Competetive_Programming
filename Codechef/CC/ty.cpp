#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // map<int, int> a;
    // a[1] = 0;
    // a[2] = 4;
    // a[3] = 5;
    // for (auto x : a)
    // {
    //     cout << x.first << " " << x.second << endl;
    //     if (x.second == 0)
    //         a.erase(x.first);
    // }
    // a.erase(1);
    // cout << endl;
    // for (auto x : a)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    vector<int>ans{1,2,3,4,5,6,7,7,8,};
    auto it=upper_bound(ans.begin(),ans.end(),6);
    cout<<it-ans.begin()<<endl;
    return 0;
}