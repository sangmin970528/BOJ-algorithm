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

vector<int> favorite[401];
int classroom[21][21];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
pair<int,int> stu[401];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=1;i<=N*N;i++)
    {
        int x;
        cin >> x;
        for(int j=1;j<=4;j++)
        {
            int f;
            cin >> f;
            favorite[x].push_back(f);
        }
        vector<pair<int,int>> like;
        for(int j=0;j<4;j++)
        {
            for(int a=1;a<=N;a++)
            {
                for(int b=1;b<=N;b++)
                {
                    if(favorite[x][j]==classroom[a][b])
                        like.push_back({a,b});
                }
            }
        }
        if(like.size()!=0) // 좋아하는 친구 있음
        {
            int dp[21][21]={0};
            for(int j=0;j<like.size();j++)
            {
                int a=like[j].first;
                int b=like[j].second;
                for(int c=0;c<4;c++)
                {
                    int nx=a+dx[c];
                    int ny=b+dy[c];
                    if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&classroom[nx][ny]==0)
                    {
                        dp[nx][ny]++;
                    }
                }
            }
            int c_max=0;
            vector<pair<int,int>> c_loca;
            for(int a=1;a<=N;a++)
            {
                for(int b=1;b<=N;b++)
                {
                    if(c_max<=dp[a][b])
                    {
                        if(c_max==dp[a][b])
                        {
                            c_loca.push_back({a,b});
                        }
                        else{
                            c_max=dp[a][b];
                            c_loca.clear();
                            c_loca.push_back({a,b});
                        }
                    }
                }
            }
            int max=0;
            vector<pair<int,int>> loca;
            
            
            for(int j=0;j<c_loca.size();j++)
            {
                int a=c_loca[j].first;
                int b=c_loca[j].second;
                int cnt=0;
                if(classroom[a][b]==0){
                    for(int c=0;c<4;c++)
                    {
                        int nx=a+dx[c];
                        int ny=b+dy[c];
                        if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&classroom[nx][ny]==0)
                        {
                            cnt++;
                        }
                    }
                    if(max<=cnt)
                    {
                        if(max==cnt)
                        {
                            loca.push_back({a,b});
                        }
                        else{
                            max=cnt;
                            loca.clear();
                            loca.push_back({a,b});
                        }
                    }
                }
            }
            sort(loca.begin(),loca.end());
            classroom[loca[0].first][loca[0].second]=x;
            stu[x]={loca[0].first,loca[0].second};
        }
        else // 좋아하는 친구 없음
        {
            int max=0;
            vector<pair<int,int>> loca;
            for(int a=1;a<=N;a++)
            {
                for(int b=1;b<=N;b++)
                {
                    int cnt=0;
                    if(classroom[a][b]==0){
                        for(int c=0;c<4;c++)
                        {
                            int nx=a+dx[c];
                            int ny=b+dy[c];
                            if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&classroom[nx][ny]==0)
                            {
                                cnt++;
                            }
                        }
                        if(max<=cnt)
                        {
                            if(max==cnt)
                            {
                                loca.push_back({a,b});
                            }
                            else{
                                max=cnt;
                                loca.clear();
                                loca.push_back({a,b});
                            }
                        }
                    }
                }
            }
            sort(loca.begin(),loca.end());
            classroom[loca[0].first][loca[0].second]=x;
            stu[x]={loca[0].first,loca[0].second};
        }
    }
    int ans=0;
    for(int i=1;i<=N*N;i++)
    {
        int x=stu[i].first;
        int y=stu[i].second;
        int cnt=0;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=1&&nx<=N&&ny>=1&&ny<=N)
            {
                for(int j=0;j<4;j++)
                {
                    if(favorite[i][j]==classroom[nx][ny])
                        cnt++;
                }
            }
        }
        if(cnt==4)
            ans+=1000;
        if(cnt==3)
            ans+=100;
        if(cnt==2)
            ans+=10;
        if(cnt==1)
            ans+=1;
        if(cnt==0)
            ans+=0;
    }
    cout << ans;
}
