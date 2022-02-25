#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
/*-------------------------------------------------------------------------------------------------*/

struct TrieNode
{
    bool isEnd;
    unordered_map<char, TrieNode *> child;
    TrieNode()
    {
        isEnd = false;
    }
    bool isEmpty()
    {
        if (child.size() == 0)
            return 1;
        else
            return 1;
    }
    bool isContainKey(char ch)
    {
        return (child.find(ch) != child.end());
    }
    TrieNode *get(char ch)
    {
        return child[ch];
    }
    void put(char ch, TrieNode *root)
    {
        child[ch] = root;
    }
    bool getEnd()
    {
        return isEnd;
    }
    void setEnd()
    {
        isEnd = true;
    }
};

struct Trie
{
private:
    TrieNode *root = new TrieNode();

public:
    void Insert(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
            {
                curr->put(str[i], new TrieNode());
            }
            curr = curr->get(str[i]);
        }
        curr->setEnd();
    }
    bool Search(string str)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!curr->isContainKey(str[i]))
            {
                return false;
            }
            curr = curr->get(str[i]);
        }
        return curr->getEnd();
    }
};

/*-----------------------------------------------------------------------------------------------------*/
vector<vector<string>> LikeIngred;
vector<vector<string>> DisLikeIngred;
map<string, int> UniqueIngred;
vector<pair<int, string>> UniqueIngred_inVec;
vector<string> sorted;
Trie *root = new Trie();
int Simulator()
{
    long long Customer_Satisfied = 0;
    int n = LikeIngred.size();
    for (int i = 0; i < n; i++)
    {
        bool Dis = false;
        for (int j = 0; j < DisLikeIngred[i].size(); j++)
        {
            if (root->Search(DisLikeIngred[i][j]))
            {
                Dis = true;
                break;
            }
        }
        if (Dis)
            continue;
        bool like = true;
        for (int j = 0; j < LikeIngred[i].size(); j++)
        {
            if (!root->Search(LikeIngred[i][j]))
            {
                like = false;
                break;
            }
        }
        if (!like)
            continue;
        Customer_Satisfied++;
    }
    return Customer_Satisfied;
}

void all_subset_solve()
{
    long long total = UniqueIngred_inVec.size(), Max_Ans = 0;
    vector<string> temp;
    int max_len = 0;
    for (int i = 0; i < total; i++)
    {
        temp.push_back(sorted[i]);
        root->Insert(temp[i]);
        int temp_ans = Simulator();
        if (Max_Ans < temp_ans)
        {
            Max_Ans = temp_ans;
            max_len = i + 1;
        }
    }
    cout << Max_Ans << "\n";
    cout << max_len << " ";
    for (int i = 0; i < max_len; i++)
    {
        string s = temp[i];
        reverse(s.begin(), s.end());
        cout << s << " ";
    }
    cout << "\n";
}

void Input()
{
    int nCust;
    cin >> nCust;
    while (nCust--)
    {
        int li, dis;
        vector<string> temp1, temp2;
        cin >> li;
        while (li--)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            temp1.push_back(s);
            UniqueIngred[s]--;
        }
        LikeIngred.push_back(temp1);
        cin >> dis;
        while (dis--)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            temp2.push_back(s);
            UniqueIngred[s]++;
        }
        DisLikeIngred.push_back(temp2);
    }
    for (auto &x : UniqueIngred)
    {
        UniqueIngred_inVec.push_back({x.second, x.first});
    }
    sort(UniqueIngred_inVec.begin(), UniqueIngred_inVec.end());
    for (auto x : UniqueIngred_inVec)
    {
        sorted.push_back(x.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    Input();
    // Output();
    // cout << Simulator(uset) << "\n";
    all_subset_solve();
    cout << "Finish\n";
    return 0;
}