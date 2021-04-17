#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace ::std;

int g[1001][1001];
int M, N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int check[1001][1001];

queue<pair<int,int>> q;

void bfs(){
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        int w=g[x][y]+1;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(check[nx][ny]==0&&g[nx][ny]==0&&nx>=1&&nx<=N&&ny>=1&&ny<=M){
                g[nx][ny]+=w;
                q.push({nx,ny});
                check[nx][ny]=1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            cin >> g[i][j];
            if(g[i][j]==1)
                q.push({i,j});
        }
    bfs();

    int max=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(g[i][j]==0)
            {
                cout << "-1";
                return 0;
            }
            if(max<g[i][j])
                max=g[i][j];
        }
    }
    cout << max-1;
}
