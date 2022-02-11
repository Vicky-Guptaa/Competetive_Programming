#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int Max = 0;
        if (n <= 2)
        {
            cout << 0 << "\n";
            continue;
        }
        int zeroc = 0, onec = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '0')
            {
                zeroc++;
            }
            else
            {
                onec++;
            }
            if (onec > zeroc)
            {
                Max = max(zeroc, Max);
            }
            else if (onec < zeroc)
            {
                Max = max(onec, Max);
            }
        }

        cout << Max << "\n";
    }
    return 0;
}