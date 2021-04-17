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

char adj[101][101];
int visited_정상[101][101];
int visited_비정상[101][101];
int cnt_정상=0;
int cnt_비정상=0;
int N;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void dfs_정상(int x, int y, char color)
{
    visited_정상[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&ny>=1&&nx<=N&&ny<=N&&adj[nx][ny]==color&&visited_정상[nx][ny]==false)
            dfs_정상(nx, ny, color);
    }
}

void dfs_비정상(int x, int y, char color)
{
    visited_비정상[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&ny>=1&&nx<=N&&ny<=N&&adj[nx][ny]==color&&color=='B'&&visited_비정상[nx][ny]==false)
            dfs_비정상(nx, ny, color);
        if(nx>=1&&ny>=1&&nx<=N&&ny<=N&&color!='B'&&visited_비정상[nx][ny]==false&&adj[nx][ny]!='B')
            dfs_비정상(nx, ny, color);
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf(" %1c",&adj[i][j]);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(visited_정상[i][j]==false)
            {
                dfs_정상(i,j,adj[i][j]);
                cnt_정상++;
            }
            if(visited_비정상[i][j]==false)
            {
                dfs_비정상(i, j, adj[i][j]);
                cnt_비정상++;
            }
        }
    }
    cout << cnt_정상 << " " << cnt_비정상;
}
