
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int> > findDistance(vector<vector<char> >& matrix, int N, int M)
{
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    queue<pair<int,int>>que;
    vector<vector<int>>answer(N,vector<int>(M,-1));
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(matrix[i][j]=='G')
            {
                que.push({i,j});
                answer[i][j]=0;
            }
        }
    }
    int steps=0;
    while(!que.empty())
    {
        int size=que.size();
        while(size--)
        {
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=N||ny>=M||nx<0||ny<0||matrix[nx][ny]=='W'||matrix[nx][ny]=='G'||answer[nx][ny]>=0)
                continue;
                answer[nx][ny]=steps;
                que.push({nx,ny});
            }
        }
        steps++;
    }

    return answer;
}

void Print(vector<vector<int>>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int N=2,M=4;
    vector<vector<char>>answer(N,vector<char>(M));
    answer={
        {'O','O','O','O'},
        {'W','W','G','G'}
    };
    Print(findDistance(answer,N,M));
    return 0;
}