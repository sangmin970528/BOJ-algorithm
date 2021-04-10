#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>

using namespace std;

int bamboo[501][501];
int dp[501][501];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool visited[501][501];
int n;

int dfs(int x, int y)
{
    bool chk=false;
    int mmax=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&bamboo[x][y]<bamboo[nx][ny]&&visited[nx][ny]==false)
        {
            chk=true;
            if(dp[nx][ny]==0){
                visited[nx][ny]=true;
                dp[nx][ny]=dfs(nx,ny);
                visited[nx][ny]=false;
            }
            mmax=max(mmax,dp[nx][ny]+1);
        }
    }
    if(chk)
    {
        return mmax;
    }
    else
        return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> bamboo[i][j];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j]==0)
                dp[i][j]=dfs(i,j);
        }
    }
    
    int k=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            k=max(k,dp[i][j]);
        }
    }
    cout << k;
}
