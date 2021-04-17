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

struct location{
    int x;
    int y;
};

struct node{
    double w;
    int u;
    int v;
};

int parent[1001];
location loc[1001];

vector<node> adj;

int getParent(int u){
    if(parent[u]==u)    return u;
    return getParent(parent[u]);
}

void unionParent(int u, int v){
    u=getParent(u);
    v=getParent(v);
    if(u<v) parent[v]=u;
    else    parent[u]=v;
}

bool isCycle(int u, int v){
    u=getParent(u);
    v=getParent(v);
    if(u==v)
        return true;
    return false;
}

bool cmp(node u, node v){
    return u.w<v.w;
}

int main() {
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        int x, y;   cin >> x >> y;
        loc[i]={x,y};
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            adj.push_back({sqrt(pow(loc[i].x-loc[j].x,2)+pow(loc[i].y-loc[j].y,2)),i,j});
            adj.push_back({sqrt(pow(loc[i].x-loc[j].x,2)+pow(loc[i].y-loc[j].y,2)),j,i});
        }
    }
    
    for(int i=1;i<=N;i++)
    parent[i]=i;
    sort(adj.begin(),adj.end(),cmp);
    for(int i=1;i<=M;i++)
    {
        int u, v; cin >> u >> v;
        unionParent(u, v);
    }
    double sum=0;
    for(int i=0;i<adj.size();i++)
    {
        if(!isCycle(adj[i].u,adj[i].v)){
            sum+=adj[i].w;
            unionParent(adj[i].u,adj[i].v);
        }
    }
    printf("%.2f",sum);
}
