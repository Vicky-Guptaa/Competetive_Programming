#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<string, int> pp;
vector<pair<int, vector<pp>>> Bande;
vector<pair<vector<int>, vector<pp>>> projects;
vector<string> BandeName;
vector<string> projectsName;
int n, m;

bool mycomp(pair<vector<int>, vector<pp>> &p1, pair<vector<int>, vector<pp>> &p2)
{
    return p1.first[1] < p2.first[1];
}
bool mycomp1(pp &p1, pp &p2)
{
    return p1.second > p2.second;
}

bool mycomp3(pair<vector<int>, vector<pp>> &p1, pair<vector<int>, vector<pp>> &p2)
{
    return p1.first[3] < p2.first[3];
}

void Print()
{
    sort(projects.begin(), projects.end(), mycomp3);
    for (auto project : projects)
    {
        cout << projectsName[project.first[4]] << " ";
        cout << project.first[1] << " ";
        cout << project.first[3] << "\n";
    }
}

void Solve()
{
    sort(projects.begin(), projects.end(), mycomp);
    for (auto band : Bande)
    {
        sort(band.second.begin(), band.second.end(), mycomp1);
    }
    vector<vector<string>> answer;
    for (auto project : projects)
    {
        vector<int> pmeta = project.first;
        vector<pp> skillreqs = project.second;
        vector<string> projectBanda;
        unordered_map<int, pair<int, int>> projectBandaindex;
        for (auto skillreq : skillreqs)
        {
            int counter = 0;
            for (auto band : Bande)
            {
                bool isAssign = 0;
                for (int i = 0; i < band.second.size(); i++)
                    if (projectBandaindex.find(counter) == projectBandaindex.end())
                        if (band.second[i].first == skillreq.first && band.second[i].second >= skillreq.second)
                        {
                            projectBanda.push_back(BandeName[band.first]);
                            projectBandaindex[counter] = {i, skillreq.second};
                            isAssign = 1;
                            break;
                        }
                counter++;
                if (isAssign)
                    break;
            }
        }
        unordered_set<string> projectBandas;
        for (auto x : projectBanda)
        {
            projectBandas.insert(x);
        }
        if (skillreqs.size() == projectBandas.size())
        {
            projectBanda.push_back(projectsName[pmeta[4]]);
            answer.push_back(projectBanda);
            for (auto x : projectBandaindex)
            {
                if (Bande[x.first].second[x.second.first].second == x.second.second)
                {
                    Bande[x.first].second[x.second.first].second++;
                }
            }
        }
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i][answer[i].size() - 1] << "\n";
        for (int j = 0; j < answer[i].size() - 1; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}

void Input()
{
    cin >> n >> m;
    int counter = 0;
    while (n--)
    {
        string s;
        int noSkill;
        cin >> s;
        cin >> noSkill;
        BandeName.push_back(s);
        vector<pp>
            skillbande;
        while (noSkill--)
        {
            string skillname;
            int level;
            cin >> skillname;
            cin >> level;
            skillbande.push_back({skillname, level});
        }
        Bande.push_back({counter, skillbande});
        counter++;
    }
    counter = 0;
    while (m--)
    {
        int k = 4;
        vector<int> metadata;
        string name;
        cin >> name;
        projectsName.push_back(name);
        while (k--)
        {
            int meta;
            cin >> meta;
            metadata.push_back(meta);
        }
        metadata.push_back(counter);
        k = metadata[3];
        vector<pp> skillbande;
        while (k--)
        {
            string skillname;
            int level;
            cin >> skillname;
            cin >> level;
            skillbande.push_back({skillname, level});
        }
        projects.push_back({metadata, skillbande});
        counter++;
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
    Solve();
    return 0;
}