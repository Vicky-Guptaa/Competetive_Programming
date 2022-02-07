#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int Maximum(unordered_map<int, int> umap)
{
    int i;
    for (i = 0; i < umap.size(); i++)
    {
        if (umap.find(i) == umap.end())
            break;
    }
    return i;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            umap[arr[i]]++;
        }
        int itr = 0;
        vector<int> answer;
        while (itr < n)
        {
            int maximum = Maximum(umap);

            unordered_set<int> uset;
            while (itr < n)
            {
                if (arr[itr] <= maximum)
                {
                    uset.insert(arr[itr]);
                }
                umap[arr[itr]]--;
                if (umap[arr[itr]] == 0)
                {
                    umap.erase(arr[itr]);
                }
                itr++;
                if (uset.size() == maximum)
                    break;
            }
            if (uset.size() == maximum)
            {
                answer.push_back(maximum);
            }
            else
            {
                answer.push_back(0);
            }
        }
        cout << answer.size() << "\n";
        for (auto x : answer)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
