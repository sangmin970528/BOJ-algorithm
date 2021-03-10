#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace ::std;

int V,E,K;
int INF=2100000000;
vector<pair<int, int>> adj[20001];

vector<int> mydijkstra(int start){
    vector<int> distance(V+1,INF);
    distance[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int here=pq.top().second;
        int dis=pq.top().first;
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
    cin >> K;
    for(int i=0;i<E;i++)
    {
        int u, v, w;  cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<int> d=mydijkstra(K);
    for(int i=1;i<=V;i++)
    {
        if(d[i]==INF)
            cout << "INF" <<'\n';
        else
            cout << d[i] << '\n';
    }
}
