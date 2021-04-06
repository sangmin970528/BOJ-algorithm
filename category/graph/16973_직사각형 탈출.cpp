#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int map[1001][1001];
bool chk[1001][1001];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool check(int ltx, int lty, int rdx, int rdy, int dir){ //dir ==0 오른쪽 1 왼쪽 2 위쪽 3 아래쪽 4
    if(chk[ltx][lty]==1)
        return false;
    if(dir==0)
    {
        for(int i=ltx;i<=rdx;i++)
            if(map[i][rdy]==1)
                return false;
    }
    if(dir==1)
    {
        for(int i=ltx;i<=rdx;i++)
            if(map[i][lty]==1)
                return false;
    }
    if(dir==2)
    {
        for(int i=lty;i<=rdy;i++)
            if(map[ltx][i]==1)
                return false;
    }
    if(dir==3)
    {
        for(int i=lty;i<=rdy;i++)
            if(map[rdx][i]==1)
                return false;
    }
    chk[ltx][lty]=1;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> map[i][j];
        }
    }
    int H, W, Sr, Sc, Fr, Fc;
    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
    
    queue<tuple<int,int,int>> q;
    q.push({Sr,Sc,0});
    while(!q.empty())
    {
        int ltx=get<0>(q.front());
        int lty=get<1>(q.front());
        int cnt=get<2>(q.front());
        q.pop();
        if(ltx==Fr&&lty==Fc)
        {
            cout << cnt;
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nltx=ltx+dx[i];
            int nlty=lty+dy[i];
            int nrdx=nltx+H-1;
            int nrdy=nlty+W-1;
            if(nltx>=1&&nlty>=1&&nrdx<=N&&nrdy<=M&&check(nltx,nlty,nrdx,nrdy,i))
            {
                q.push({nltx,nlty,cnt+1});
            }
        }
    }
    cout << -1;
}
