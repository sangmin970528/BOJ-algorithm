#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <map>
#include <set>

using namespace std;

int maze[101][101];
int check[101][101];
int dp[101][101];
int M, N;
int Min=999999;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main()
{
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            scanf("%1d",&maze[i][j]);
        }
    }
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    q.push({1,1});
    check[1][1]=1;
    int n=0;
    while(dp[N][M]==0){
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            if(n==0&&x==N&&y==M)
            {
                cout << 0;
                exit(0);
            }
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=1&&ny>=1&&nx<=N&&ny<=M&&check[nx][ny]==0&&maze[nx][ny]==0)
                {
                    check[nx][ny]=1;
                    dp[nx][ny]=n;
                    q.push({nx,ny});
                }
                if(nx>=1&&ny>=1&&nx<=N&&ny<=M&&check[nx][ny]==0&&maze[nx][ny]==1)
                {
                    check[nx][ny]=1;
                    dp[nx][ny]=n+1;
                    v.push_back({nx,ny});
                }
            }
        }
        n++;
        for(int i=0;i<v.size();i++)
        q.push({v[i].first,v[i].second});
        v.clear();
    }
    cout << dp[N][M];
}
