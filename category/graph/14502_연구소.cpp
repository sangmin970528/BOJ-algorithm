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
int N, M;
int map[9][9]={0};
int check[9][9]={0};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int>> q;
int cnt=0;
int maximum=0;
int n_check[9][9]={0};

void bfs(){
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1&&nx<=N&&ny>=1&&ny<=M&&map[nx][ny]==0&&n_check[nx][ny]==0&&check[nx][ny]==0)
            {
                n_check[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(map[i][j]==0&&n_check[i][j]==0)
                ans++;
        }
    }
    ans-=3;
    if(ans>maximum)
        maximum=ans;
    return;
}

void arr_free(){
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++){
            n_check[i][j]=0;
            if(map[i][j]==2)
                q.push({i,j});
        }
    }
}

void find_wall(int size)
{
    if(size==3){
        bfs();
        arr_free();
        return;
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(check[i][j]==0)
            {
                check[i][j]=1;
                find_wall(size+1);
                check[i][j]=0;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> map[i][j];
            if(map[i][j]==2)
                q.push({i,j});
            if(map[i][j]!=0)
                check[i][j]=1;
        }
    }
    find_wall(0);
    cout << maximum;
}
