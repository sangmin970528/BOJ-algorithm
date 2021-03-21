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
    int N; cin >> N;
    queue<pair<int,int>> q;
    int check[1000001]={0};
    int dp[1000001]={0};
    vector<int> ans;
    q.push({N,0});
    while(!q.empty())
    {
        int v=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(v==1)
        {
            cout << cnt << '\n';
            int x=v;
            ans.push_back(x);
            while(dp[x])
            {
                ans.push_back(dp[x]);
                x=dp[x];
            }
            for(int i=0;i<ans.size();i++)
            {
                cout << ans[ans.size()-i-1] <<" ";
            }
            return 0;
        }
        if(v%3==0)
        {
            int x=v/3;
            if(x>0&&check[x]==0){
                check[x]=1;
                q.push({x,cnt+1});
                dp[x]=v;
            }
        }
        if(v%2==0)
        {
            int x=v/2;
            if(x>0&&check[x]==0){
                check[x]=1;
                q.push({x,cnt+1});
                dp[x]=v;
            }
        }
        int x=v-1;
        if(x>0&&check[x]==0){
            check[x]=1;
            q.push({x,cnt+1});
            dp[x]=v;
        }
    }
}
