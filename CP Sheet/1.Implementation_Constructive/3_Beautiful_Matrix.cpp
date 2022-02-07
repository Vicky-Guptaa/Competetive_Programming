#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        vector<vector<int>> matrix(5, vector<int>(5, 0));
        int answer = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == 1)
                {
                    answer += abs(2 - i) + abs(2 - j);
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}