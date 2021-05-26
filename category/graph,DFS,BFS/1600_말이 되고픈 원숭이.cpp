#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int map[201][201];

int ddx[]={-2,-1,1,2,2,1,-1,-2};
int ddy[]={1,2,2,1,-1,-2,-2,-1};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool visited[201][201][31];

int main(){
    int K; cin >> K;
    int W, H; cin >> W >> H;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            cin >> map[i][j];
        }
    }
    queue<tuple<int,int,int,int>> q;
    vector<int> cnts;
    q.push({1,1,0,0});
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int cnt=get<2>(q.front());
        int k=get<3>(q.front());
        q.pop();
        if(x==H&&y==W)
        {
            cnts.push_back(cnt);
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1&&ny>=1&&nx<=H&&ny<=W&&visited[nx][ny][k]==false&&map[nx][ny]==0)
            {
                q.push({nx,ny,cnt+1,k});
                visited[nx][ny][k]=true;
            }
        }
        if(k<K)
        {
            for(int i=0;i<8;i++)
            {
                int nx=x+ddx[i];
                int ny=y+ddy[i];
                if(nx>=1&&ny>=1&&nx<=H&&ny<=W&&visited[nx][ny][k+1]==false&&map[nx][ny]==0)
                {
                    q.push({nx,ny,cnt+1,k+1});
                    visited[nx][ny][k+1]=true;
                }
            }
        }
    }
    if(cnts.empty())
        cout << -1;
    else{
        sort(cnts.begin(),cnts.end());
        cout << cnts[0];
    }
}
