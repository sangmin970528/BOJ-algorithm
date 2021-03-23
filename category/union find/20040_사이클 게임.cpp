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

using namespace ::std;

vector<int> parent(500001,-1);
vector<int> Rank(500001);

int root(int u)
{
    if(parent[u]==u)    return u;
    return parent[u]=root(parent[u]);
}

void merge(int u, int v)
{
    u=root(u);
    v=root(v);
    
    if(u==v) return;
    if(Rank[u]<Rank[v]) swap(u,v);
    
    parent[u]=v;
    if(Rank[u]==Rank[v]) Rank[v]++;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int index=0;
    for(int i=1;i<=m;i++)
    {
        int x, y; cin >> x >> y;
        if(parent[x]==-1)
            parent[x]=x;
        if(parent[y]==-1)
            parent[y]=y;
        if(index==0&&root(x)==root(y))
            index=i;
        merge(x,y);
    }
    cout << index;
}

