#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int N;
vector<int> node[1000001];
int dp[1000001][2];
bool visited[1000001];


void dfs(int cur) {
    visited[cur]=true;
    dp[cur][0]=0;
    dp[cur][1]=1;
    for(int i=0;i<node[cur].size();i++)
    {
        int next = node[cur][i];
        if(!visited[next]) {
            dfs(next);
            dp[cur][0]+=dp[next][1];
            dp[cur][1]+=min(dp[next][0],dp[next][1]);
        }
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0],dp[1][1]);
}
