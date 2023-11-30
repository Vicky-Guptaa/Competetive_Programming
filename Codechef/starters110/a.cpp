#include <iostream>
using namespace std;

int helper(int a, int b)
{
    if (a % b == 0)
        return 0;

    int oper = 0;
    oper++;
    a++;
    b--;
    while (b)
    {
        if (a % b == 0)
            return oper;
        b--;
        a++;
        oper++;
    }
    return oper;
}

int helper2(int a, int b)
{
    if (a % b == 0)
        return 0;

    int oper = 0;
    b++;
    a--;
    oper++;
    while (a)
    {
        if (a % b == 0)
            return oper;
        b++;
        a--;
        oper++;
    }
    return 1e9;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << min(helper(a, b), helper2(a, b)) << "\n";
    }
    return 0;
}
