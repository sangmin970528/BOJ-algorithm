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

struct node{
    int w;
    int u;
    int v;
};
int parent[10001];
vector<node> adj;
int V, E;

int getParent(int v){
    if(parent[v]==v) return v;
    return getParent(parent[v]);
}

void unionParent(int u, int v){
    u = getParent(u);
    v = getParent(v);
    if(u<v) parent[v]=u;
    else    parent[u]=v;
}

bool isCycle(int u, int v){
    u = getParent(u);
    v = getParent(v);
    if(u==v)
        return true;
    return false;
}

bool cmp(node u, node v){
    return u.w<v.w;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for(int i=1;i<=E;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w,u,v});
    }
    sort(adj.begin(),adj.end(),cmp);
    for(int i=1;i<=V;i++)
    parent[i]=i;
    int sum=0;
    for(int i=0;i<adj.size();i++)
    {
        if(!isCycle(adj[i].u,adj[i].v)){
            sum+=adj[i].w;
            unionParent(adj[i].u,adj[i].v);
        }
    }
    cout << sum;
}
