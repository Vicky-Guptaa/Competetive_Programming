#include <bits/stdc++.h>
using namespace std;

void Reorder(string str)
{
    unordered_map<char, int> freq;
    for (auto x : str)
    {
        freq[x]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto x : freq)
    {
        pq.push(make_pair(x.second, x.first));
    }

    char pal[str.length() + 1] = {"\0"};

    int i = 0;
    while (pq.size() > 0)
    {
        if (pq.top().first == 1)
            break;
        int count = pq.top().first - 2;
        char ch = pq.top().second;
        pq.pop();
        pal[i] = ch;
        pal[str.length() - 1 - i] = ch;
        if (count > 0)
        {
            pq.push(make_pair(count, ch));
        }
        i++;
    }
    if (pq.size() == 1)
    {
        pal[i] = pq.top().second;
        pq.pop();
    }
    else if (pq.size() > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    cout << pal << endl;
}

int main()
{
    string str;
    cin >> str;
    Reorder(str);
    return 0;
}