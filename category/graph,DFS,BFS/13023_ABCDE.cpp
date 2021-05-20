#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> adj[2001];
bool chk[2001];
int N, M;

void dfs(int v, int depth)
{
    if(5==depth)
    {
        cout << 1;
        exit(0);
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(chk[adj[v][i]]==false)
        {
            chk[adj[v][i]]=true;
            dfs(adj[v][i],depth+1);
            chk[adj[v][i]]=false;
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i=1;i<=M;i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<=N;i++)
    {
        dfs(i,0);
    }
    cout << 0;
}
