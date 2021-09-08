#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

int N, R, Q;
int dp[100001];
bool visited[100001];
vector<int> node[100001];

int cntNodes(int startNode)
{
    if(visited[startNode])
        return dp[startNode];
    visited[startNode]=true;
    for(int i=0;i<node[startNode].size();i++)
    {
        if(!visited[node[startNode][i]])
            dp[startNode]+=cntNodes(node[startNode][i]);
    }
    return dp[startNode];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> R >> Q;
    for(int i=1;i<=N;i++)
        dp[i]=1;
    for(int i=0;i<N-1;i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        node[v1].push_back(v2);
        node[v2].push_back(v1);
    }
    cntNodes(R);
    for(int i=0;i<Q;i++)
    {
        int s;
        cin >> s;
        cout << dp[s] << '\n';
    }
}
