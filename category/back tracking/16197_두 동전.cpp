#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
char map[21][21];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int answer = 11;

bool check(int x, int y) {
    return x<1||x>N||y<1||y>M;
}

void move(int x1, int y1, int x2, int y2, int depth) {
    if(depth>9)
        return;
    for(int i=0;i<4;i++)
    {
        int nx1 = x1+dx[i];
        int ny1 = y1+dy[i];
        int nx2 = x2+dx[i];
        int ny2 = y2+dy[i];
        if(!check(nx1, ny1)&&!check(nx2, ny2)&&map[nx1][ny1]=='#'&&map[nx2][ny2]!='#')
            move(x1,y1,nx2,ny2,depth+1);
        if(!check(nx1, ny1)&&!check(nx2, ny2)&&map[nx1][ny1]!='#'&&map[nx2][ny2]=='#')
            move(nx1,ny1,x2,y2,depth+1);
        if(!check(nx1, ny1)&&!check(nx2, ny2)&&map[nx1][ny1]!='#'&&map[nx2][ny2]!='#')
            move(nx1,ny1,nx2,ny2,depth+1);
        if(check(nx1, ny1)&&!check(nx2, ny2))
            answer = min(answer,depth+1);
        if(!check(nx1, ny1)&&check(nx2, ny2))
            answer = min(answer,depth+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<pair<int,int>> v;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> map[i][j];
            if(map[i][j]=='o')
                v.push_back({i,j});
        }
    }
    move(v[0].first,v[0].second,v[1].first,v[1].second,0);
    if(answer==11)
        cout << -1;
    else
        cout << answer;
}

