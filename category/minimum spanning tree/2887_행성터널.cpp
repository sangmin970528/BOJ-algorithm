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

struct loc{
    int x;
    int y;
    int z;
    int index;
};

int parent[100001];
vector<node> adj;
vector<loc> location;

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

bool cmpx(loc u, loc v){
    return u.x<v.x;
}

bool cmpy(loc u, loc v){
    return u.y<v.y;
}

bool cmpz(loc u, loc v){
    return u.z<v.z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        location.push_back({x,y,z,i});
    }
    sort(location.begin(),location.end(),cmpx);
    for(int i=1;i<n;i++)
    {
        int u=location[i].index;
        int v=location[i-1].index;
        int w=location[i].x-location[i-1].x;
        adj.push_back({w,u,v});
    }
    sort(location.begin(),location.end(),cmpy);
    for(int i=1;i<n;i++)
    {
        int u=location[i].index;
        int v=location[i-1].index;
        int w=location[i].y-location[i-1].y;
        adj.push_back({w,u,v});
    }
    sort(location.begin(),location.end(),cmpz);
    for(int i=1;i<n;i++)
    {
        int u=location[i].index;
        int v=location[i-1].index;
        int w=location[i].z-location[i-1].z;
        adj.push_back({w,u,v});
    }
    sort(adj.begin(),adj.end(),cmp);
    for(int i=1;i<=n;i++)
    parent[i]=i;
    int sum=0;
    for(int i=0;i<adj.size();i++)
    {
        if(!isCycle(adj[i].u, adj[i].v)){
            sum+=adj[i].w;
            unionParent(adj[i].u, adj[i].v);
        }
    }
    
    cout << sum;
}
