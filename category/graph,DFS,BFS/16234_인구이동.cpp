#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int N, L ,R;
int map[51][51];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool check[51][51];
int sum=0;

int bfs(int i, int j)
{
    sum=map[i][j];
    vector<pair<int,int>> v;
    queue<pair<int,int>> q;
    q.push({i,j});
    v.push_back({i,j});
    int ccnt=0;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&check[nx][ny]==false&&abs(map[x][y]-map[nx][ny])>=L&&abs(map[x][y]-map[nx][ny])<=R)
            {
                check[nx][ny]=true;
                int cccchk=false;
                for(int e=0;e<v.size();e++)
                {
                    if(v[e].first==nx&&v[e].second==ny)
                        cccchk=true;
                }
                if(!cccchk)
                {
                   v.push_back({nx,ny});
                   sum+=map[nx][ny];
                }
                q.push({nx,ny});
            }
        }
        ccnt++;
    }
    sum/=v.size();
    for(int k=0;k<v.size();k++)
    {
        map[v[k].first][v[k].second]=sum;
    }
    return ccnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
        }
    }
    while(true){
        bool chk=false;
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        check[i][j]=false;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(check[i][j]==false)
                {
                    if(bfs(i,j)!=1)
                        chk=true;
                }
            }
        }
        if(!chk)
            break;
        cnt++;
    }
    cout << cnt;
}
