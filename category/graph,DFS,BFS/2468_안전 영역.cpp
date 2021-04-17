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

using namespace std;

int Map[101][101];
int check[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;

void dfs(int x, int y, int height)
{
    check[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&check[nx][ny]==0&&Map[nx][ny]>height)
            dfs(nx,ny,height);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int mmax=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> Map[i][j];
            if(Map[i][j]>mmax)
                mmax=Map[i][j];
        }
    }
    int max=0;
    for(int height=1;height<=mmax;height++)
    {
        
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            check[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(Map[i][j]<=height)
                    check[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(check[i][j]==0){
                    cnt++;
                    dfs(i,j,height);
                }
            }
        }
        if(max<cnt)
            max=cnt;
    }
    if(max==0)
        max=1;
    cout << max;
    
}
