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

const int INF=2100000000;
int N, M;
vector<pair<int, int>> adj[1001];

vector<int> dijkstra(int start){
    vector<int> distance(N+1,INF);
    distance[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int here=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        if(distance[here]<dis)
            continue;
        for(int i=0;i<adj[here].size();i++)
        {
            int next=adj[here][i].first;
            int next_dis=adj[here][i].second;
            if(distance[next]>next_dis+dis){
                distance[next]=next_dis+dis;
                pq.push({distance[next],next});
            }
        }
    }
    return distance;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1;i<=M;i++)
    {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    int start, end; cin >> start >> end;
    vector<int> d=dijkstra(start);
    cout  << d[end];
}

