#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    string d1, d2;
    cin >> d1 >> d2;
    int h1 = stoi(d1.substr(0, 2));
    int h2 = stoi(d2.substr(0, 2));
    int m1 = stoi(d1.substr(3, 2));
    int m2 = stoi(d2.substr(3, 2));
    int diff = (h2 - h1) * 60 + (m2 - m1);
    diff /= 2;
    string newh = to_string(h1 + diff / 60 + (m1 + diff % 60) / 60);
    string newm = to_string((m1 + diff % 60) % 60);
    if (newm.size() == 1)
    {
        newm = "0" + newm;
    }
    if (newh.size() == 1)
    {
        newh = "0" + newh;
    }

    cout << newh << ":" << newm << "\n";
    return 0;
}