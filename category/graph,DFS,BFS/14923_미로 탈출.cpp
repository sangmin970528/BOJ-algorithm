#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maze[1001][1001];
int visited[1001][1001][2];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main(){
    int N, M;
    cin >> N >> M;
    int Hx, Hy;
    cin >> Hx >> Hy;
    int Ex, Ey;
    cin >> Ex >> Ey;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> maze[i][j];
        }
    }
    queue<tuple<int,int,int>> q;
    visited[Hx][Hy][0]=1;
    visited[Hx][Hy][1]=1;
    q.push({Hx, Hy, 0});
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int breakNum=get<2>(q.front());
        q.pop();
        if(x==Ex&&y==Ey)
        {
            cout << visited[x][y][breakNum]-1;
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1&&ny>=1&&nx<=N&&ny<=M){
                if(maze[nx][ny]==0) {
                    if(visited[nx][ny][breakNum]==0)
                    {
                        visited[nx][ny][breakNum]=visited[x][y][breakNum]+1;
                        q.push({nx,ny,breakNum});
                    }
                }
                else {
                    if(visited[nx][ny][breakNum]==0&&breakNum==0)
                    {
                        visited[nx][ny][1]=visited[x][y][0]+1;
                        q.push({nx,ny,1});
                    }
                }
            }
        }
    }
    cout << -1;
}
