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
    double w;
    int u;
    int v;
};
int parent[100001];
vector<node> adj;

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
    int n; cin >> n;
    vector<pair<int,int>> location;
    for(int i=1;i<=n;i++)
    {
        double x, y;
        cin >> x >> y;
        location.push_back({x,y});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int u=i;
            int v=j;
            double w=sqrt(pow(location[i-1].first-location[j-1].first,2)+pow(location[i-1].second-location[j-1].second,2));
            adj.push_back({w,u,v});
        }
    }
    sort(adj.begin(),adj.end(),cmp);
    for(int i=1;i<=n;i++)
    parent[i]=i;
    double sum=0;
    for(int i=0;i<adj.size();i++)
    {
        if(!isCycle(adj[i].u, adj[i].v)){
            sum+=adj[i].w;
            unionParent(adj[i].u, adj[i].v);
        }
    }
    cout << sum;
}
