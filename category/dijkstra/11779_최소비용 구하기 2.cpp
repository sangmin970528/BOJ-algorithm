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
vector<pair<int,int>> adj[1001];
int go[1001];
vector<int> route;
int N, M;

vector<int> dijkstra(int start)
{
    vector<int> dist(N+1,INF);
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({start,0});
    while(!pq.empty())
    {
        int here=pq.top().first;
        int distance=pq.top().second;
        pq.pop();
        if(distance>dist[here])
            continue;
        for(int i=0;i<adj[here].size();i++)
        {
            int next=adj[here][i].first;
            int next_dist=adj[here][i].second;
            if(dist[next]>next_dist+distance)
            {
                go[next]=here;
                dist[next]=next_dist+distance;
                pq.push({next,dist[next]});
            }
        }
    }
    return dist;
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
    cout << d[end] << '\n';
    int temp=end;
    while(temp)
    {
        route.push_back(temp);
        temp=go[temp];
    }
    cout << route.size() << '\n';
    for(int i=route.size()-1;i>=0;i--)
    cout << route[i] << " ";
}

