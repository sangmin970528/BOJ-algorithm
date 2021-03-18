#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace ::std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int dx[]={2,1,2,1,-1,-2,-1,-2};
    int dy[]={1,2,-1,-2,2,1,-2,-1};
    while(t--)
    {
        int l; cin >> l;
        int visit[300][300]={0};
        int s1, s2; cin >> s1 >> s2;
        int e1, e2; cin >> e1 >> e2;
        
        queue<tuple<int,int,int>> q;
        
        q.push({s1,s2,0});
        while(!q.empty())
        {
            int x=get<0>(q.front());
            int y=get<1>(q.front());
            int cnt=get<2>(q.front());
            q.pop();
            if(x==e1&&y==e2){
                cout<<cnt<<'\n';
                break;
            }
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<l&&ny<l&&nx>=0&&ny>=0&&visit[nx][ny]==0)
                {
                    visit[nx][ny]=1;
                    q.push({nx,ny,cnt+1});
                }
            }
        }
    }
}
