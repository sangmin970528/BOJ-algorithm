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

int N, M, K;
int map[1001][1001];
bool check[1001][1001][11];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs()
{
    queue<tuple<int, int, int, int>> q;
    q.push({1,1,0,1});
    check[1][1][0]=1;
    while(!q.empty())
    {
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int crash=get<2>(q.front());
        int cnt=get<3>(q.front());
        q.pop();
        if(x==N&&y==M)
        {
            cout << cnt <<endl;
            return;
        }
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx>N||ny>M||nx<=0||ny<=0)
                continue;
            if(check[nx][ny][crash]==0&&map[nx][ny]==0){
                check[nx][ny][crash]=1;
                q.push({nx,ny,crash,cnt+1});
            }
            if(check[nx][ny][crash]==0&&map[nx][ny]==1&&crash<K){
                check[nx][ny][crash+1]=1;
                q.push({nx,ny,crash+1,cnt+1});
            }
        }
    }
    cout << -1 << endl;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 1; j <= Inp.size(); j++)
        {
            int I_Inp = Inp[j-1] - '0';
            map[i][j] = I_Inp;
        }
    }
    
    bfs();
}
