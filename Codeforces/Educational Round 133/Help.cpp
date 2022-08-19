#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int count_invalid_boxes(vector<vector<string>> box_template_list)
{
    int cnt = 0;
    for (auto x : box_template_list)
    {
        string s1 = x[0], s2 = x[1];
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 != s2)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<string>> data;
    for (int i = 0; i < 6; i++)
    {
        string x, y;
        cin >> x >> y;
        data.push_back({x, y});
    }
    cout << count_invalid_boxes(data) << '\n';
    return 0;
}