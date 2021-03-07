#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <limits>

using namespace ::std;

vector<int> tree[100001];
int parent[100001];
int check[100001];
int N;

void dfs(int v){
    check[v]=1;
    for(int i=0;i<tree[v].size();i++)
    {
        int next=tree[v][i];
        if(check[next]==0&&next!=0)
        {
            parent[next]=v;
            dfs(next);
        }
    }
}
void bfs(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<tree[x].size();i++)
        {
            int next=tree[x][i];
            if(check[next]==0)
            {
                q.push(next);
                check[next]=1;
                parent[next]=x;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<N;i++)
    {
        int x; cin >> x;
        int y; cin >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    for(int i=2;i<=N;i++)
    cout << parent[i] << '\n';
}
