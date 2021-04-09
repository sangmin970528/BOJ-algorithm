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

vector<int> node[32001];
vector<int> topology(32001);
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    queue<int> q;
    for(int i=1;i<=M;i++)
    {
        int A, B; cin >> A >> B;
        node[A].push_back(B);
        topology[B]++;
    }
    for(int i=1;i<=N;i++)
        if(topology[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        v.push_back(x);
        for(int k=0;k<node[x].size();k++)
        {
            topology[node[x][k]]--;
            if(topology[node[x][k]]==0)
                q.push(node[x][k]);
        }
    }
    v.erase(unique(v.begin(), v.end()),v.end());
    for(int i=0;i<v.size();i++)
    cout << v[i] << " ";
}
