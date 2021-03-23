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

vector<int> parent(501);
vector<int> Rank(501);
set<int> roots;
vector<int> check;

int root(int u)
{
    if(u==parent[u]) return u;
    return parent[u]=root(parent[u]);
}

bool merge(int u, int v)
{
    u=root(u);
    v=root(v);
    if(u==v) return true;
    if(Rank[u]<Rank[v]) swap(u,v);
    parent[u]=v;
    if(Rank[u]==Rank[v]) Rank[v]++;
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cnt=1;
    while(true){
        parent.clear();
        Rank.clear();
        roots.clear();
        check.clear();
        int n, m; cin >> n >> m;  // n : 정점개수 , m : 간선개수
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;i++)
            parent[i]=i;
        
        for(int i=1;i<=m;i++)
        {
            int u, v; cin >> u >> v;
            bool iscycle=merge(u,v);
            if(iscycle)
            {
                check.push_back(u);
            }
        }
        for(int i=1;i<=n;i++)
        {
            roots.insert(root(i));
        }
        for(int i=0;i<check.size();i++)
        {
            roots.erase(root(check[i]));
        }
        
        if(roots.size()==0)
        {
            cout << "Case " << cnt << ": No trees.\n";
        }
        else if(roots.size()==1)
        {
            cout << "Case " << cnt << ": There is one tree.\n";
        }
        else if(roots.size()>1)
        {
            cout << "Case " << cnt << ": A forest of " << roots.size() << " trees.\n";
        }
        cnt++;
    }
}

