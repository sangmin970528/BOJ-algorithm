#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <map>
#include <set>

using namespace std;

struct flight{
    int v;
    int c;
    int d;
};

vector<flight> adj[101];
const int INF=999999999;
int N, M, K;
int dp[101][10001];

void dijkstra(int v)
{
    queue<tuple<int,int,int>> q;
    q.push({0,0,v});
    dp[1][0]=0;
    while(!q.empty())
    {
        int cur_d=get<0>(q.front());
        int cur_c=get<1>(q.front());
        int cur=get<2>(q.front());
        q.pop();
        if(dp[cur][cur_c]<cur_d)
            continue;
        for(int i=0;i<adj[cur].size();i++)
        {
            int next=adj[cur][i].v;
            int next_d=dp[cur][cur_c]+adj[cur][i].d;
            int next_c=cur_c+adj[cur][i].c;
            if(next_c>10000)
                continue;
            if(dp[next][next_c]>next_d)
            {
                dp[next][next_c]=next_d;
                q.push({next_d,next_c,next});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;  cin >> T;
    while(T--)
    {
        for(int i=1;i<=100;i++)
        adj[i].clear();
        cin >> N >> M >> K;
        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                dp[i][j]=INF;
            }
        }
        for(int i=1;i<=K;i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >>d;
            adj[u].push_back({v,c,d});
        }
        dijkstra(1);
        int Min=INF;
        for(int i=0;i<=M;i++)
            Min=min(dp[N][i],Min);
        if(Min==INF)
            cout << "Poor KCM\n";
        else
            cout << Min << '\n';
    }
}
