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

int V,E,V1,V2;
long long INF=LLONG_MAX;
vector<pair<int, int>> adj[801];

vector<long long> mydijkstra(int start){
    vector<long long> distance(V+1,INF);
    distance[start]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        long long here=pq.top().second;
        long long dis=pq.top().first;
        pq.pop();
        if(distance[here]<dis)
            continue;
        for(int i=0;i<adj[here].size();i++)
        {
            int there=adj[here][i].first;
            int nextDis=adj[here][i].second;
            if(distance[there]>nextDis+dis){
                distance[there]=nextDis+dis;
                pq.push({distance[there],there});
            }
        }
    }
    return distance;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        int u, v, w;  cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> V1 >> V2;
    vector<long long> d1=mydijkstra(1);
    long long t=mydijkstra(V1)[V2];
    vector<long long> d2=mydijkstra(V);
    
    if(d1[V1]==INF||d2[V2]==INF||t==INF)
    {
        cout << -1;
        return 0;
    }
    
    long long x=min(d1[V1]+d2[V2]+t,d1[V2]+d2[V1]+t);
    cout << x;
    
}
