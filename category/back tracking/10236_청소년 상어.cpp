#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct fish_info{
    int number;
    int x;
    int y;
    int dir;
    int eaten;
};
bool cmp(fish_info f1, fish_info f2)
{
    return f1.number < f2.number;
}
int dx[]={0,-1,-1,0,1,1,1,0,-1};
int dy[]={0,0,-1,-1,-1,0,1,1,1};
int max_sum=0;
void back_tracking(int s, int shark_dir, pair<int,int> shark_loca,vector<fish_info> fishs){
    for(int i=0;i<fishs.size();i++)
    {
        int dir=fishs[i].dir;
        int cnt=0;
        if(fishs[i].eaten==1)
            continue;
        while(true)
        {
            if(cnt==8)
                break;
            cnt++;
            int nx=fishs[i].x+dx[dir];
            int ny=fishs[i].y+dy[dir];
            if(nx>=0 && nx<4 && ny>=0 && ny<4 && (nx!=shark_loca.first || ny!=shark_loca.second))
            {
                for(int j=0;j<fishs.size();j++)
                {
                    if(fishs[j].x==nx&&fishs[j].y==ny)
                    {
                        int t_x=fishs[j].x;
                        int t_y=fishs[j].y;
                        fishs[j].x=fishs[i].x;
                        fishs[j].y=fishs[i].y;
                        fishs[i].x=t_x;
                        fishs[i].y=t_y;
                        fishs[i].dir=dir;
                        break;
                    }
                }
                break;
            }
            else
            {
                dir++;
                if(dir==9)
                    dir=1;
            }
        }
    }
    for(int i=0;i<fishs.size();i++)
    {
        int x=fishs[i].x;
        int y=fishs[i].y;
        if(fishs[i].eaten==1)
            continue;
        for(int j=1;j<=3;j++)
        {
            int nx=shark_loca.first+j*dx[shark_dir];
            int ny=shark_loca.second+j*dy[shark_dir];
            if(nx==x&&ny==y)
            {
                fishs[i].eaten=1;
                back_tracking(s+fishs[i].number, fishs[i].dir, {x,y}, fishs);
                fishs[i].eaten=0;
                break;
            }
        }
    }
    max_sum=max(s,max_sum);
    return;
}

int main(){
    int a,b;
    int sum=0;
    int shark_dir=0;
    vector<fish_info> _fishs;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> a >> b;
            _fishs.push_back({a,i,j,b,0});
            if(i==0&&j==0)
            {
                shark_dir=b;
                sum=a;
                _fishs[0].eaten=1;
            }
        }
    }
    sort(_fishs.begin(),_fishs.end(),cmp);
    back_tracking(sum,shark_dir,{0,0},_fishs);
    cout << max_sum;
}
