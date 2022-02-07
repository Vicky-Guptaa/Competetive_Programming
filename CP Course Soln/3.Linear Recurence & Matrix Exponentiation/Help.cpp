#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s)
{
    int len1 = pattern.length(), len2 = s.length();
    unordered_map<char, string> umap;
    int i, j;
    for (i = 0, j = 0; i < len1 && j < len2; i++)
    {
        string word;
        while (len2 > j && s[j] != ' ')
        {
            word += s[j++];
        }
        j++;
        if (umap.find(pattern[i]) == umap.end())
        {
            umap[pattern[i]] = word;
        }
        else
        {
            if (word.compare(umap[pattern[i]]) != 0)
            {
                return false;
            }
        }
    }
    if (i < len1 || j < len2)
        return false;
    else
        return true;
}

int main()
{
    cout << wordPattern("abba", "dog cat cat dog") << "\n";
    return 0;
}