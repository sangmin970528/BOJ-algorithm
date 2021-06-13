#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main(){
    int cnt=0;
    while(true)
    {
        cnt++;
        int N; cin >> N;
        if(N==0)
            break;
        int map[126][126]={0};
        int dp[126][126]={0};
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                cin >> map[i][j];
                dp[i][j]=9999999;
            }
        }

        queue<pair<int,int>> q;
        q.push({1,1});
        dp[1][1]=map[1][1];
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=1&&ny>=1&&nx<=N&&ny<=N)
                {
                    int d=dp[x][y]+map[nx][ny];
                    if(dp[nx][ny]>d)
                    {
                        dp[nx][ny]=d;
                        q.push({nx,ny});
                    }
                }
            }
        }
        printf("Problem %d: %d\n",cnt,dp[N][N]);
    }
}

