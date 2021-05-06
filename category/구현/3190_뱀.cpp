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

int map[101][101];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int N;
int K;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> K;
    queue<pair<int,char>> time;
    queue<pair<int,int>> head;
    queue<pair<int,int>> tail;
    for(int i=1;i<=K;i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y]=4;
    }
    int L; cin >> L;
    for(int i=1;i<=L;i++)
    {
        int X;
        char C;
        cin >> X >> C;
        time.push({X,C});
    }
    int t=0;
    int dir=0;
    head.push({1,1});
    tail.push({1,1});
    map[1][1]=1;
    while(true)
    {
        if(!time.empty()&&t==time.front().first)
        {
            if(time.front().second=='L'){
                if(dir==0)
                    dir=3;
                else
                dir=dir-1;
            }
            else
                dir=(dir+1)%4;
            time.pop();
        }
        int nx=head.front().first+dx[dir];
        int ny=head.front().second+dy[dir];
        if(nx<1||nx>N||ny<1||ny>N)
            break;
        if(map[nx][ny]==1)
            break;
        if(map[nx][ny]==4){
            tail.push({nx,ny});
            head.push({nx,ny});
            head.pop();
            map[nx][ny]=1;
        }
        else{
            map[tail.front().first][tail.front().second]=0;
            tail.push({nx,ny});
            tail.pop();
            head.push({nx,ny});
            head.pop();
            map[nx][ny]=1;
        }
        t++;
    }
    cout << t+1;
}
