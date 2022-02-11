#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> MatMulti(vector<vector<long long int>> mat1, vector<vector<long long int>> mat2, int n)
{
    vector<vector<long long int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> row;
        for (int j = 0; j < n; j++)
        {
            long long int num = 0;
            for (int k = 0; k < n; k++)
            {
                num += ((mat2[i][k] % 998244353) * (mat1[k][j] % 998244353)) % 998244353;
            }
            row.push_back(num);
        }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<long long int>> Multi_Int(vector<vector<long long int>> mat, long long int num, long long int n)
{
    vector<vector<long long int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> row(n);
        for (int j = 0; j < n; j++)
        {
            row[j] = ((mat[i][j] % 998244353) * (num % 998244353)) % 998244353;
        }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<long long int>> Addition(vector<vector<long long int>> mat1, vector<vector<long long int>> mat2, int n)
{
    vector<vector<long long int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> row(n);
        for (int j = 0; j < n; j++)
        {
            row[j] = ((mat1[i][j] % 998244353) + (mat2[i][j] % 998244353)) % 998244353;
        }
        ans.push_back(row);
    }
    return ans;
}

bool Check(vector<vector<long long int>> mat, long long int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        long long int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        int n;
        cin >> n;
        vector<vector<long long int>> mat, mat1, ans;
        for (int i = 0; i < n; i++)
        {
            vector<long long int> row(n);
            vector<long long int> row1(n);
            for (int j = 0; j < n; j++)
            {
                cin >> row[j];
            }
            mat1.push_back(row);
            mat.push_back(row);
            ans.push_back(row1);
        }

        if (arr[0] != 0)
            for (int i = 0; i < n; i++)
            {
                ans[i][i] = (arr[0] % 998244353);
            }
        vector<vector<long long int>> ans2;
        if (arr[1] != 0)
        {
            ans2 = Multi_Int(mat1, arr[1], n);
            ans = Addition(ans, ans2, n);
        }

        for (int i = 2; i < m; i++)
        {
            mat = MatMulti(mat, mat1, n);
            if (arr[i] != 0)
            {
                ans2 = Multi_Int(mat, arr[i], n);
                ans = Addition(ans, ans2, n);
            }
        }
        if (Check(ans, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*
1
4
-6 11 -6 1
3
1 2 -1
1 0 1
4 -4 5


A
1 2 -1
1 0 1
4 -4 5

A*A
-1	6	-4
5	-2	4
20	-12	17

A*A*A
-11	14	-13
19	-6	13
76	-28	53

-6I

-6 0 0
0 -6 0
0 0 -6

11A
11 22 -11
11 0 11
44 -44 55

ans->
5 22 -11
11 -6 11
44 -44 49

-6A*A
6 -36 24
-30 12 -24
-120 72 -102

ans->
11 -14 13
-19 6 -13
-76 28 -53

*/