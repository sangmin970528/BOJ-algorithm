#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int map[301][301];
bool chk[301][301];
int temp_map[301][301];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int N, M;

void dfs(int x, int y)
{
    chk[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=N&&ny>=1&&ny<=M&&map[nx][ny]!=0&&chk[nx][ny]==false)
            dfs(nx,ny);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> map[i][j];
    int time=0;
    while(true)
    {
        time++;
        bool check=true;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(map[i][j]!=0)
                {
                    check=false;
                    break;
                }
            }
            if(!check)
                break;
        }
        if(check)
        {
            cout << 0;
            break;
        }
        memset(temp_map,0,sizeof(temp_map));
        memset(chk,0,sizeof(chk));
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(map[i][j]!=0)
                {
                    int cnt=0;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=1&&nx<=N&&ny>=1&&ny<=M&&map[nx][ny]==0)
                            cnt++;
                    }
                    if(map[i][j]-cnt<=0)
                        temp_map[i][j]=0;
                    else
                        temp_map[i][j]=map[i][j]-cnt;
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                map[i][j]=temp_map[i][j];
            }
        }
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(chk[i][j]==false&&map[i][j]!=0)
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        if(cnt>=2)
        {
            cout << time;
            break;
        }
    }
}
