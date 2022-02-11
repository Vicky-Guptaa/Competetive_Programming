#include <iostream>
#include <climits>
#include <string.h>
using namespace std;
string appends(int n)
{
    if (n == 1)
    {
        return "I";
    }
    if (n == 4)
    {
        return "IV";
    }
    if (n == 9)
    {
        return "V";
    }
    if (n == 10)
    {
        return "X";
    }
    if (n == 5)
    {
        return "V";
    }
    if (n == 50)
    {
        return "L";
    }
    if (n == 100)
    {
        return "C";
    }
    if (n == 90)
    {
        return "XC";
    }
    if (n == 400)
    {
        return "CD";
    }
    if (n == 500)
    {
        return "D";
    }
    if (n == 900)
    {
        return "CM";
    }
    if (n == 1000)
    {
        return "M";
    }
    return "";
}
int main()
{
    int n;
    cout << "ENTER YOUR NUMBER" << endl;
    cin >> n;
    int a[12] = {1, 4, 9, 10, 50, 90, 100, 400, 500, 900, 1000};
    int i = 0;
    string res;
    while (n >= a[i])
    {
        int temp = n - a[i];
        res += appends(temp);
        i++;
    }
    for (int i = 0; i <= '\0'; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}