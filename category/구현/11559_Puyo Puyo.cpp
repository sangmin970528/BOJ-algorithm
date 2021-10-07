#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string map[12];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int cnt = 0;
bool visited[12][6];
vector<pair<int,int>> v;

void dfs(int x, int y ,char cur) {
    visited[x][y]=true;
    v.push_back({x,y});
    cnt++;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<12&&ny>=0&&ny<6&&!visited[nx][ny]&&map[nx][ny]==cur)
            dfs(nx,ny,cur);
    }
}

void down() {
    int t=12;
    while(t--) {
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(map[i+1][j]=='.'&&map[i][j]!='.') {
                    map[i+1][j]=map[i][j];
                    map[i][j]='.';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int answer = 0;
    for(int i=0;i<12;i++)
        cin >> map[i];
    while(true) {
        bool chk = false;
        for(int i=0;i<12;i++)
            for(int j=0;j<6;j++)
                visited[i][j]=false;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<6;j++)
            {
                v.clear();
                cnt = 0;
                if(map[i][j]!='.')
                {
                    dfs(i,j,map[i][j]);
                    if(cnt>=4)
                    {
                        for(int i=0;i<v.size();i++)
                            map[v[i].first][v[i].second]='.';
                        chk=true;
                    }
                }
            }
        }
        if(!chk)
            break;
        down();
        answer++;
    }
    cout << answer;
}

