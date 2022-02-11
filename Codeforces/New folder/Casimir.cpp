#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'A')
                a++;
            else if (str[i] == 'B')
                b++;
            else if (str[i] == 'C')
                c++;
        }
        a += c;
        if (a == b)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
    return 0;
}