#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    vector<int> arr;
    for (int i = 0; i < s.length(); i += 2)
    {
        arr.push_back(s[i] - '0');
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
        {
            cout << arr[i] << "\n";
        }
        else
        {
            cout << arr[i] << "+";
        }
    }
    return 0;
}