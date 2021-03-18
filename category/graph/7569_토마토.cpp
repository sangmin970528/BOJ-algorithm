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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M, N, H; cin >> M >> N >> H;
    int map[100][100][100]={0};
    queue<tuple<int,int,int,int>> q;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                cin >> map[i][j][k];
                if(map[i][j][k]==1){
                    q.push({i,j,k,0});
                }
            }
        }
    }
    int dx[]={0,0,0,0,1,-1};
    int dy[]={0,0,1,-1,0,0};
    int dz[]={1,-1,0,0,0,0};
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int z=get<2>(q.front());
        int cnt=get<3>(q.front());
        q.pop();
        for(int i=0;i<6;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];
            if(nx>=0&&nx<H&&ny>=0&&ny<N&&nz>=0&&nz<M)
            {
                if(map[nx][ny][nz]==0)
                {
                    map[nx][ny][nz]=cnt+1;
                    q.push({nx,ny,nz,cnt+1});
                }
            }
        }
    }
    int max=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                if(map[i][j][k]==0){
                    cout <<-1;
                    return 0;
                }
                if(max<map[i][j][k])
                    max=map[i][j][k];
            }
        }
    }
    if(max==1)
        cout << 0;
    else
        cout << max;
}
