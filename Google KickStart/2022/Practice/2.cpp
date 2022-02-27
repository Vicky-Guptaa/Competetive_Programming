#include <iostream>
#include <string>

using namespace std;

string GetRuler(const string &kingdom)
{
    // TODO: implement this method to determine the ruler name, given the kingdom.
    int len = kingdom.length() - 1;
    string ruler = "";
    if (kingdom[len] == 'Y' || kingdom[len] == 'y')
    {
        return ruler = "nobody";
    }
    char arr[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (auto x : arr)
    {
        if (kingdom[len] == x)
            return ruler = "Alice";
    }
    return ruler = "Bob";
}

int main()
{
    int testcases;
    cin >> testcases;
    string kingdom;

    for (int t = 1; t <= testcases; ++t)
    {
        cin >> kingdom;
        cout << "Case #" << t << ": " << kingdom << " is ruled by "
             << GetRuler(kingdom) << ".\n";
    }
    return 0;
}
