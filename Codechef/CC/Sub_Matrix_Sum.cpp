#include <iostream>
using namespace std;

int Sub_Matrix(int **arr, int N, int M, int p, int k)
{
    int Count = 0;
    for (int i = 0; i < N - p + 1; i++)
    {
        for (int j = 0+M; j < N - p + 1+M; j++)
        {
            float Sum = 0;
            for (int q = i; q < i + p; q++)
            {
                for (int r = j; r < j + p; r++)
                {
                    Sum += arr[q][r];
                }
            }
            Sum /= (p)*(p);
            if (Sum >= k)
                Count++;
        }
    }
    return Count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        int **arr = new int *[N];
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int[M];
            for (int j = 0; j < M; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] >= K)
                {
                    count++;
                }
            }
        }
        for (int j = 0; j <=M - N; j++)
        {
            for (int i = 2; i <= N; i++)
            {
                count += Sub_Matrix(arr, N, j, i, K);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}