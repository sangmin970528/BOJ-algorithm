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

int map[50][50]={0};
int check[50][50]={0};
int N, M;
int cnt=0;

void dfs(int x, int y, int d, int c)
{
    if(check[x][y]==0)
    {
        check[x][y]=1;
        cnt++;
    }
    if(d==0)//북쪽
    {
        int ny=y-1;
        if(ny<0)
            return;
        if(ny>=0&&map[x][ny]==0&&check[x][ny]==0)
        {
            return dfs(x,ny,3,0); //서쪽으로 돌기
        }
        if(c<4&&ny>=0&&(map[x][ny]==1||check[x][y]==1))
        {
            return dfs(x,y,3,c+1);
        }
        int nx=x+1;
        if(nx>=N&&map[nx][y]==1)
            return;
        if(nx<N&&c==4&&map[nx][y]==0)
            return dfs(nx,y,0,0);
    }
    if(d==1)//동쪽
    {
        int nx=x-1;
        if(nx<0)
            return;
        if(nx>=0&&map[nx][y]==0&&check[nx][y]==0)
        {
            return dfs(nx,y,0,0); //북쪽으로 돌기
        }
        if(c<4&&nx>=0&&(map[nx][y]==1||check[nx][y]==1))
        {
            return dfs(x,y,0,c+1);
        }
        int ny=y-1;
        if(ny>=M&&map[x][ny]==1)
            return;
        if(ny<M&&c==4&&map[x][ny]==0)
            return dfs(x,ny,1,0);
    }
    if(d==2)//남쪽
    {
        int ny=y+1;
        if(ny>=M)
            return;
        if(ny<M&&map[x][ny]==0&&check[x][ny]==0)
        {
            return dfs(x,ny,1,0); //동쪽으로 돌기
        }
        if(c<4&&ny<M&&(map[x][ny]==1||check[x][y]==1))
        {
            return dfs(x,y,1,c+1);
        }
        int nx=x-1;
        if(nx<0&&map[nx][y]==1)
            return;
        if(nx>=0&&c==4&&map[nx][y]==0)
            return dfs(nx,y,2,0);
    }
    if(d==3)//서쪽
    {
        int nx=x+1;
        if(nx>=N)
            return;
        if(nx<N&&map[nx][y]==0&&check[nx][y]==0)
        {
            return dfs(nx,y,2,0); //남쪽으로 돌기
        }
        if(c<4&&nx<N&&(map[nx][y]==1||check[nx][y]==1))
        {
            return dfs(x,y,2,c+1);
        }
        int ny=y+1;
        if(ny<0&&map[x][ny]==1)
            return;
        if(ny>=0&&c==4&&map[x][ny]==0)
            return dfs(x,ny,3,0);
    }
    return;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int r, c, d; cin >> r >> c >>d;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> map[i][j];
        }
    }
    dfs(r,c,d,0);
    cout << cnt;
}
           
