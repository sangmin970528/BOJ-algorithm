#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int map[21][21];

bool cmp(tuple<int,int,int> t1, tuple<int,int,int> t2){
    if(get<0>(t1)==get<0>(t2))
    {
        if(get<1>(t1)==get<1>(t2))
            return get<2>(t1) < get<2>(t2);
        else
            return get<1>(t1) < get<1>(t2);
    }
    else
        return get<0>(t1) < get<0>(t2);
}


int main(){
    int N; cin >> N;
    int time=0;
    int w=0;
    pair<int,int> shark_location;
    int shark_scale = 2;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
            if(map[i][j]==9)
                shark_location={i,j};
        }
    }
    while(true){
        int fishs=0;
        bool visited[21][21]={0};
        vector<tuple<int,int,int>> v;
        queue<tuple<int,int,int>> q;
        q.push({shark_location.first,shark_location.second,0});
        visited[shark_location.first][shark_location.second]=true;
        while(!q.empty())
        {
            int x=get<0>(q.front());
            int y=get<1>(q.front());
            int t=get<2>(q.front());
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&map[nx][ny]<=shark_scale&&visited[nx][ny]==false)
                {
                    q.push({nx,ny,t+1});
                    visited[nx][ny]=true;
                    if(map[nx][ny]!=0&&map[nx][ny]<shark_scale)
                    {
                        fishs++;
                        v.push_back({t+1,nx,ny});
                    }
                }
            }
        }
        
        if(fishs==0)
            break;
        sort(v.begin(),v.end(),cmp);
        time+=get<0>(v[0]);
        int nx=get<1>(v[0]);
        int ny=get<2>(v[0]);
        map[shark_location.first][shark_location.second]=0;
        map[nx][ny]=9;
        shark_location={nx,ny};
        w++;
        if(w==shark_scale)
        {
            w=0;
            shark_scale++;
        }
    }
    cout << time;
}
