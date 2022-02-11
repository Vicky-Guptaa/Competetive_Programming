#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    unordered_set<char> uset;
    for (auto x : s)
    {
        uset.insert(x);
    }
    if (uset.size() & 1)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }
    return 0;
}