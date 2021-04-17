#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>

using namespace ::std;

const int INF=999999999;
int N;
bool board[19][19];
bool check[19][19];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void init(){
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    check[i][j]=board[i][j];
}

void toggle(bool *x){
    if(*x==1)
        *x=0;
    else
        *x=1;
}

void click(int x, int y){
    toggle(&check[x][y]);
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=N&&ny>=1&&ny<=N)
            toggle(&check[nx][ny]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> board[i][j];
    int set=(1<<N)-1;
    int ans=INF;
    for(int subset=set;;subset=(subset-1)&set)
    {
        init();
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            int b=(1<<(i-1));
            if((b|subset)==subset){
                click(1,i);
                cnt++;
            }
        }
        for(int i=2;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(check[i-1][j]==1){
                    click(i, j);
                    cnt++;
                }
            }
        }
        bool chk=true;
        for(int i=1;i<=N;i++)
        {
            if(check[N][i]==1)
                chk=false;
        }
        if(chk)
            ans=min(ans,cnt);
        if(!subset)
            break;
    }
    if(ans==INF)
        cout << -1;
    else
        cout << ans;
}
