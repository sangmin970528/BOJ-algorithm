#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        vector<int> Time(1001);
        vector<int> in_v[1001];
        vector<int> out_v[1001];
        vector<int> in(1001);
        int N, K;
        cin >> N >> K;
        for(int i=1;i<=N;i++)
            cin >> Time[i];
        for(int i=1;i<=K;i++)
        {
            int x, y; cin >> x >> y;
            in_v[y].push_back(x);
            out_v[x].push_back(y);
            in[y]++;
        }
        int dp[1001]={0};
        queue<int> q;
        for(int i=1;i<=N;i++)
            if(in[i]==0)
                q.push(i);
        int W; cin >> W;
        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            if(in_v[vertex].size()==0)
                dp[vertex]+=Time[vertex];
            else{
                for(int i=0;i<in_v[vertex].size();i++)
                {
                    dp[vertex]=max(dp[vertex],dp[in_v[vertex][i]]+Time[vertex]);
                }
            }
            for(int i=0;i<out_v[vertex].size();i++)
            {
                in[out_v[vertex][i]]--;
                if(in[out_v[vertex][i]]==0)
                    q.push(out_v[vertex][i]);
            }
        }
        cout << dp[W] << '\n';
    }
    
}
