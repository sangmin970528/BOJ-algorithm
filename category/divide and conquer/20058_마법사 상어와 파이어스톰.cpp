#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int map[65][65];
int temp_map[65][65];
bool visited[65][65];
int cccnt=0;
vector<int> L;

void dfs(int x, int y, int s)
{
    visited[x][y]=true;
    cccnt++;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&ny>=0&&nx<=s&&ny<=s&&visited[nx][ny]==false&&map[nx][ny]!=0)
            dfs(nx,ny,s);
    }
}

void recur(int x1, int y1, int x2, int y2, int size , int s){
    if(size==x2-x1+1)
    {
        int cnt=size/2;
        if(cnt==0)
            temp_map[x1][y1]=map[x1][y1];
        else{
            while(cnt--)
            {
                for(int i=y1,j=x2;i<=y2;i++,j--)
                    temp_map[x1][i]=map[j][y1];
                for(int i=x1,j=y1;i<=x2;i++,j++)
                    temp_map[i][y2]=map[x1][j];
                for(int i=y2,j=x1;i>=y1;i--,j++)
                    temp_map[x2][i]=map[j][y2];
                for(int i=x2,j=y2;i>=x1;i--,j--)
                    temp_map[i][y1]=map[x2][j];
                x1++;
                y1++;
                x2--;
                y2--;
            }
        }
        return;
    }
    else{
        int t=s/2;
        recur(x1,y1,x2-s/2,y2-s/2,size,t);
        recur(x1,y2-s/2+1,x2-s/2,y2,size,t);
        recur(x2-s/2+1,y1,x2,y2-s/2,size,t);
        recur(x2-s/2+1,y2-s/2+1,x2,y2,size,t);
    }
}

int main(){
    int N, Q;
    cin >> N >> Q;
    int n=pow(2,N);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> map[i][j];
    for(int i=1;i<=Q;i++)
    {
        int q; cin >> q;
        L.push_back(q);
    }
    for(int i=0;i<L.size();i++)
    {
        for(int a=1;a<=n;a++)
            for(int b=1;b<=n;b++)
                temp_map[a][b]=0;
        int size=pow(2,L[i]);
        recur(1,1,n,n,size,n);
        for(int a=1;a<=n;a++)
            for(int b=1;b<=n;b++)
                map[a][b]=temp_map[a][b];
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=n;b++)
            {
                if(map[a][b]==0)
                    continue;
                int cnt=0;
                for(int k=0;k<4;k++)
                {
                    int nx=a+dx[k];
                    int ny=b+dy[k];
                    if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&map[nx][ny]!=0)
                        cnt++;
                }
                if(cnt<3)
                    temp_map[a][b]--;
            }
        }
        
        for(int a=1;a<=n;a++)
            for(int b=1;b<=n;b++)
                map[a][b]=temp_map[a][b];
    }
    int sum=0;
    int mmmax=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum+=map[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(map[i][j]!=0&&visited[i][j]==false)
            {
                dfs(i,j,n);
                mmmax=max(mmmax,cccnt);
                cccnt=0;
            }
        }
    }
    cout << sum << '\n';
    cout << mmmax;
}
