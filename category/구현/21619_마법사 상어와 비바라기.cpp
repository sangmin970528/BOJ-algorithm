#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int map[50][50];
int dx[]={0,0,-1,-1,-1,0,1,1,1};
int dy[]={0,-1,-1,0,1,1,1,0,-1};
int ddx[]={1,1,-1,-1};
int ddy[]={1,-1,1,-1};

int main(){
    int N, M; cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    vector<pair<int,int>> cloud_info;
    vector<int> D;
    vector<int> S;
    cloud_info.push_back({N-1,0});
    cloud_info.push_back({N-1,1});
    cloud_info.push_back({N-2,0});
    cloud_info.push_back({N-2,1});
    for(int i=1;i<=M;i++)
    {
        int d, s;
        cin >> d >> s;
        for(int j=0;j<cloud_info.size();j++)
        {
            if((cloud_info[j].first+s*dx[d])%N<0)
                cloud_info[j].first=(cloud_info[j].first+s*dx[d])%N+N;
            else
                cloud_info[j].first=(cloud_info[j].first+s*dx[d])%N;
            if((cloud_info[j].second+s*dy[d])%N<0)
                cloud_info[j].second=(cloud_info[j].second+s*dy[d])%N+N;
            else
                cloud_info[j].second=(cloud_info[j].second+s*dy[d])%N;
            map[cloud_info[j].first][cloud_info[j].second]++;
        }
        for(int j=0;j<cloud_info.size();j++)
        {
            for(int k=0;k<4;k++)
            {
                int nx=cloud_info[j].first+ddx[k];
                int ny=cloud_info[j].second+ddy[k];
                if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]>0)
                    map[cloud_info[j].first][cloud_info[j].second]++;
            }
        }
        vector<pair<int,int>> temp_info=cloud_info;
        cloud_info.clear();
        for(int a=0;a<N;a++)
        {
            for(int b=0;b<N;b++)
            {
                if(map[a][b]>=2)
                {
                    bool chk=true;
                    for(int k=0;k<temp_info.size();k++)
                    {
                        if(a==temp_info[k].first&&b==temp_info[k].second)
                        {
                            chk=false;
                            break;
                        }
                    }
                    if(chk)
                    {
                        cloud_info.push_back({a,b});
                        map[a][b]-=2;
                    }
                }
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            sum+=map[i][j];
    cout << sum;
}

