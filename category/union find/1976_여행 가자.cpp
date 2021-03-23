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

vector<int> parent(201);
vector<int> Rank(201,0);

int root(int u)
{
    if(u==parent[u]) return u;
    return parent[u]=root(parent[u]);
}

void merge(int u, int v)
{
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(Rank[u]>Rank[v]) swap(u,v);
    
    parent[u]=v;
    if(Rank[u]==Rank[v]) Rank[v]++;
    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    int M; cin >> M;
   
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int x; cin >> x;
            if(x==1)
            {
                if(parent[i]==0)
                    parent[i]=i;
                if(parent[j]==0)
                    parent[j]=j;
                merge(i,j);
            }
        }
    }
    int temp=0;
    for(int i=1;i<=M;i++)
    {
        int x; cin >> x;
        if(i>=2)
        {
            if(root(temp)!=root(x))
            {
                cout << "NO";
                return 0;
            }
        }
        temp=x;
    }
    cout << "YES";
}

