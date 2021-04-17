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


int T;
int M, N, K;
int map[50][50]={0};
int check[50][50]={0};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void dfs(int x, int y)
{
    check[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<M&&ny>=0&&ny<N&&check[nx][ny]==0&&map[nx][ny]==1)
            dfs(nx,ny);
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        fill(check[0], check[0]+2500,1);
        fill(map[0], map[0]+2500,0);
        int cnt=0;
        for(int i=0;i<K;i++)
        {
            int x, y; cin >> x >> y;
            map[x][y]=1;
            check[x][y]=0;
        }
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(map[i][j]==1&&check[i][j]==0){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
