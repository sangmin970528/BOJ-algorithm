#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

char map[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int visited[51][51];
bool water_v[51][51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C;
    cin >> R >> C;
    int water_cnt=0;
    queue<pair<int, int>> q;
    vector<pair<int,int>> water;
    pair<int,int> destination;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin >> map[i][j];
            if(map[i][j]=='S')
                q.push({i,j});
            if(map[i][j]=='D')
                destination={i,j};
            if(map[i][j]=='*'){
                water.push_back({i,j});
                water_v[i][j]=true;
            }
        }
    }
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==destination.first&&y==destination.second)
        {
            cout << visited[x][y];
            return 0;
        }
        if(water_cnt==visited[x][y]){
            int s = (int)water.size();
            for(int i=0;i<s;i++)
            {
                int w_x=water[i].first;
                int w_y=water[i].second;
                for(int j=0;j<4;j++)
                {
                    int w_nx = w_x+dx[j];
                    int w_ny = w_y+dy[j];
                    if(w_nx>=1&&w_nx<=R&&w_ny>=1&&w_ny<=C&&water_v[w_nx][w_ny]==false&&(map[w_nx][w_ny]=='.'))
                    {
                        water_v[w_nx][w_ny]=true;
                        map[w_nx][w_ny]='*';
                        water.push_back({w_nx,w_ny});
                    }
                }
            }
            water.erase(water.begin(),water.begin()+s);
            water_cnt++;
        }
        
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1&&nx<=R&&ny>=1&&ny<=C&&visited[nx][ny]==0&&map[nx][ny]!='*'&&map[nx][ny]!='X')
            {
                visited[nx][ny] = visited[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout << "KAKTUS";
}
