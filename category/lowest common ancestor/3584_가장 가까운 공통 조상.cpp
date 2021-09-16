#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node{
    int parent;
    vector<int> child;
};

bool visited[10001];
bool chk[10001] = {0};
int depth[10001];
Node node[10001];

void dfs(int cur, int d) {
    visited[cur]=true;
    depth[cur]=d;
    for(int i=0;i<node[cur].child.size();i++)
    {
        int next = node[cur].child[i];
        if(!visited[next])
            dfs(next, d+1);
    }
}

int lca(int u, int v)
{
    if(depth[u]==depth[v])
    {
        if(u==v)
            return u;
        else
            return lca(node[u].parent,node[v].parent);
    }
    else if(depth[u]>depth[v])
        return lca(node[u].parent,v);
    else
        return lca(u,node[v].parent);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        for(int i=0;i<=10000;i++)
        {
            visited[i]=false;
            chk[i]=false;
            node[i].parent=-1;
            node[i].child.clear();
            depth[i]=0;
        }
        
        int N; cin >> N;
        int root = -1;

        for(int i=0;i<N-1;i++)
        {
            int A, B;
            cin >> A >> B;
            chk[B]=true;
            node[B].parent=A;
            node[A].child.push_back(B);
        }
        for(int i=1;i<=N;i++)
            if(!chk[i])
                root=i;
        dfs(root,1);
        int node1, node2;
        cin >> node1 >> node2;
        cout << lca(node1,node2) << '\n';
    }
}
