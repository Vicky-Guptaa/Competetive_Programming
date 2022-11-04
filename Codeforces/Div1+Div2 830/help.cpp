#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

int minMutation(string start, string end, vector<string> &bank)
{
    set<string> sset(bank.begin(), bank.end());
    queue<string> que;
    que.push(start);
    int oper = -1;
    string convert = "ACGT";
    while (!que.empty())
    {
        oper++;
        int size = que.size();
        while (size--)
        {
            string curr = que.front();
            que.pop();
            if (curr == end)
            {
                return oper;
            }
            for (int i = 0; i < curr.size(); i++)
            {
                for (auto ch : convert)
                {
                    curr[i] = ch;
                    if (sset.count(curr))
                    {
                        sset.erase(curr);
                        que.push(curr);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<string> bank = {"AACCGGTA"};
    cout << minMutation("AACCGGTT", "AACCGGTA", bank) << endl;
    cout << "\n";
    return 0;
}