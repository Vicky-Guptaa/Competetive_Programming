#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        char ch;
        cin >> ch;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (ch == str[i])
                counter++;
        }
        long long answer = 1;
        if (counter < 3)
        {
            if (counter == 2)
                cout << 1 << "\n";
            else
                cout << "0\n";
            continue;
        }
        for (int i = 1; i < counter; i++)
        {
            answer += i;
            answer %= 1000000007;
        }
        cout << answer << "\n";
    }
    return 0;
}