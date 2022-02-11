#include <bits/stdc++.h>
using namespace std;

void spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int tr = 0, tc = 0, lr = r - 1, lc = c - 1;
    int total = r * c;
    while (total > 0 && tr <= lr && tc <= lc)
    {
        for (int i = tc; i <= lc && total-- > 0; ++i)
        {
            cout << matrix[tr][i] << " ";
        }
        tr++;
        for (int i = tr; i <= lr && total-- > 0; ++i)
        {
            cout << matrix[i][lc] << " ";
        }
        lc--;
        for (int i = lc; i >= tc && total-- > 0; --i)
        {
            cout << matrix[lr][i] << " ";
        }
        lr--;
        for (int i = lr; i >= tr && total-- > 0; --i)
        {
            cout << matrix[i][tc] << " ";
        }
        tc++;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for (int i = 0; i < n; i++)
    {
        vector<int> col(m);
        for (int j = 0; j < m; j++)
        {
            cin >> col[j];
        }
        mat.push_back(col);
    }
    spirallyTraverse(mat, n, m);
    return 0;
}