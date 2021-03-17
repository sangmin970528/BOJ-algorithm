#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace ::std;

int g[501][501];
int cnt=0;
int M, N;
int check[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dp[501][501];

int dfs(int x, int y)
{
    if(x==M&&y==N)  return 1;
    if(dp[x][y]!=-1)    return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>M||ny>N)  continue;
        if(g[nx][ny]<g[x][y]&&g[nx][ny]!=0)
            dp[x][y]+=dfs(nx,ny);
    }
    return dp[x][y];
}

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++){
            cin >> g[i][j];
            dp[i][j]=-1;
        }
    cout << dfs(1,1);
}
