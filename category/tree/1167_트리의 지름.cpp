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

vector<pair<int,int>> tree[100001];
int check[100001];
int d_node[100001];

void dfs(int v, int d){
    check[v]=1;
    d_node[v]+=d;
    for(int i=0;i<tree[v].size();i++)
    {
        int next=tree[v][i].first;
        if(check[next]==0&&next!=0){
            dfs(next,tree[v][i].second+d);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int V; cin >> V;
    int t=V;
    while(V--){
        int main_v; cin >> main_v;
        while(true){
            int x;cin >> x;
            if(x==-1)
                break;
            int y;cin >> y;
            tree[main_v].push_back({x,y});
        }
    }
    dfs(1,0);
    int max=0;
    int vertex=0;
    for(int i=1;i<=t;i++){
        if(d_node[i]>max){
            vertex=i;
            max=d_node[i];
        }
        check[i]=0;
        d_node[i]=0;
    }
    dfs(vertex,0);
    max=0;
    for(int i=1;i<=t;i++){
        if(d_node[i]>max)
            max=d_node[i];
    }
    cout << max;
}
