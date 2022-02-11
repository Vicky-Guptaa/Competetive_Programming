#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int wordc = 1;
    string dec, word;
    for (int i = 0; i < n; i++)
    {
        word += s[i];
        if (wordc == word.length())
        {
            dec += word[0];
            word = "";
            wordc++;
        }
    }
    cout << dec << "\n";
    return 0;
}