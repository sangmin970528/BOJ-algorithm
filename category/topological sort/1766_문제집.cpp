#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[32001];
int input_degree[32001];

int main()
{
    int N, M;
    cin >> N >> M;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(int i=1;i<=M;i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        input_degree[B]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(input_degree[i]==0)
            pq.push(i);
    }
    vector<int> v;
    while(!pq.empty())
    {
        int x=pq.top();
        pq.pop();
        ans.push_back(x);
        for(int i=0;i<adj[x].size();i++)
        {
            input_degree[adj[x][i]]--;
            if(input_degree[adj[x][i]]==0)
                pq.push(adj[x][i]);
        }
    }
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << ' ';
}
