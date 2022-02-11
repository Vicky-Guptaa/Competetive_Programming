#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

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

int main()
{

    return 0;
}