#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> node[10001];
int cnt[10001];
int dp[10001][2];
int visited[10001];

void dfs(int cur)
{
    if(visited[cur])
        return;
    visited[cur]=true;
    dp[cur][0]=0;
    dp[cur][1]=cnt[cur];
    
    for(int i=0;i<node[cur].size();i++)
    {
        if(!visited[node[cur][i]]){
            dfs(node[cur][i]);
            dp[cur][0]+=max(dp[node[cur][i]][0],dp[node[cur][i]][1]);
            dp[cur][1]+=dp[node[cur][i]][0];
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> cnt[i];
    }
    for(int i=0;i<N-1;i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        node[v1].push_back(v2);
        node[v2].push_back(v1);
    }
    dfs(1);
    cout << max(dp[1][0],dp[1][1]);
}
