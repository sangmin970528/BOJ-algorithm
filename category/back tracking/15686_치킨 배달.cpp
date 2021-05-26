#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct location{
    int x;
    int y;
};

int map[51][51];
int N, M;
int min_dis=9999999;
bool visited[14];

vector<location> house;
vector<location> chicken;
vector<location> temp_chicken;

void recur(int cnt, int start){
    if(cnt==M)
    {
        int sum=0;
        for(int i=0;i<house.size();i++)
        {
            int x=house[i].x;
            int y=house[i].y;
            int mmin=9999;
            for(int j=0;j<temp_chicken.size();j++)
            {
                mmin=min(mmin,abs(x-temp_chicken[j].x)+abs(y-temp_chicken[j].y));
            }
            sum+=mmin;
        }
        min_dis=min(min_dis,sum);
        return;
    }
    for(int i=start;i<chicken.size();i++)
    {
        temp_chicken.push_back(chicken[i]);
        recur(cnt+1,i+1);
        temp_chicken.pop_back();
    }
}


int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
            if(map[i][j]==1)
                house.push_back({i,j});
            if(map[i][j]==2)
                chicken.push_back({i,j});
        }
    }
    recur(0,0);
    cout << min_dis;
}
