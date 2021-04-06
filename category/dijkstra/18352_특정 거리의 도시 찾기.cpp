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

vector<pair<int,int>> adj[300001];
int N, M, K, X;
const int INF=2100000000;

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
        if(dist[here]<distance)
            continue;
        for(int i=0;i<adj[here].size();i++)
        {
            int next=adj[here][i].first;
            int next_dist=adj[here][i].second;
            if(dist[next]>distance+next_dist)
            {
                dist[next]=distance+next_dist;
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
    cin >> N >> M >> K >> X;
    for(int i=1;i<=M;i++)
    {
        int A, B; cin >> A >> B;
        adj[A].push_back({B,1});
    }
    vector<int> d=dijkstra(X);
    vector<int> ans;
    for(int i=1;i<=N;i++)
    {
        if(K==d[i])
            ans.push_back(i);
    }
    if(ans.size()==0)
        cout << -1;
    else{
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        cout << ans[i] << '\n';
    }
}

