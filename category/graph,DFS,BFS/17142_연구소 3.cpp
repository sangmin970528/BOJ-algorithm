#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[51][51];
int temp_map[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
//0빈칸 1 벽 2 바이러스
vector<pair<int,int>> virus;
vector<pair<int,int>> temp_virus;
bool visited[2500];
int N, M;
int min_cnt=999999999;
int cnt=-1;

void bfs(){
    queue<pair<int,int>> q;
    int chk[51][51]={0};
    for(int i=0;i<temp_virus.size();i++)
    {
        q.push({temp_virus[i].first,temp_virus[i].second});
    }
    int ccnt=0;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        if(ccnt<M)
            chk[x][y]=0;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=1&&ny>=1&&ny<=N&&nx<=N&&chk[nx][ny]==0&&(temp_map[nx][ny]==0||temp_map[nx][ny]==2))
            {
                if(temp_map[nx][ny]==2)
                {
                    chk[nx][ny]=chk[x][y]+1;
                    q.push({nx,ny});
                }
                else{
                    temp_map[nx][ny]=3;
                    chk[nx][ny]=chk[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        ccnt++;
    }
    bool check=false;
    bool check2=false;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(temp_map[i][j]==0)
            {
                check=true;
                break;
            }
            if(temp_map[i][j]==3)
            {
                cnt=max(cnt,chk[i][j]);
                check2=true;
            }
        }
    }
    if(check)
    {
        cnt=999999999;
        return;
    }
    if(!check&&!check2)
    {
        cnt=0;
    }
}

void dfs(int depth,int s)
{
    if(depth==M)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                temp_map[i][j]=map[i][j];
            }
        }
        bfs();
        min_cnt=min(min_cnt,cnt);
        cnt=-1;
        return;
    }
    for(int i=s;i<virus.size();i++)
    {
        temp_virus.push_back(virus[i]);
        dfs(depth+1,i+1);
        temp_virus.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
            if(map[i][j]==2)
            {
                virus.push_back({i,j});
            }
        }
    }
    
    dfs(0,0);
    if(min_cnt==999999999)
        cout << -1;
    else
        cout << min_cnt;
}
