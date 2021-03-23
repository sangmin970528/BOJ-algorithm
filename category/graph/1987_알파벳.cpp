#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <map>
#include <set>

using namespace ::std;

int R, C;
char Map[21][21];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int Max=-1;
bool alpa_check[27];

void dfs(int x,int y,int cnt)
{
    if(Max<cnt)
        Max=cnt;
    
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=R&&ny>=1&&ny<=C)
        {
            if(alpa_check[Map[nx][ny]-'A'+1]==0)
            {
                alpa_check[Map[nx][ny]-'A'+1]=true;
                dfs(nx,ny,cnt+1);
                alpa_check[Map[nx][ny]-'A'+1]=false;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> R >> C;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin >> Map[i][j];
        }
    }
    alpa_check[Map[1][1]-'A'+1]=true;
    dfs(1,1,1);
    cout << Max;
}

