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

vector<pair<int,int>> adj[1001];
int N, M, X;
int INF=999999999;

vector<int> dijkstra(int v){
    vector<int> distance(N+1,INF);
    distance[v]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({v,0});
    
    while(!pq.empty())
    {
        int current = pq.top().first;
        int current_w = pq.top().second;
        pq.pop();
        if(current_w>distance[current])
            continue;
        for(int i=0;i<adj[current].size();i++)
        {
            int next=adj[current][i].first;
            int next_w=adj[current][i].second;
            if(next_w+current_w<distance[next]){
                distance[next]=next_w+current_w;
                pq.push({next,distance[next]});
            }
        }
    }
    return distance;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    for(int i=1;i<=M;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<int> v1 = dijkstra(X);
    int Max=0;
    for(int i=1;i<=N;i++)
    {
        vector<int> v2 = dijkstra(i);
        Max=max(Max,v2[X]+v1[i]);
    }
    cout << Max;
}
