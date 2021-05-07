#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> adj[10001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    int Max=0;
    for(int i=0;i<M;i++)
    {
        int A, B, C;    cin >> A >> B >> C;
        if(Max<C)
            Max=C;
        adj[A].push_back({B,C});
        adj[B].push_back({A,C});
    }
    int x, y;
    cin >> x >> y;
    int left=0;
    int right=Max;
    int answer=0;
    while(left<=right)
    {
        bool chk=false;
        int mid=(left+right)/2;
        bool visited[10001]={0};
        queue<int> q;
        q.push(x);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==y){
                chk=true;
                break;
            }
            for(int i=0;i<(int)adj[node].size();i++)
            {
                int next=adj[node][i].first;
                int w=adj[node][i].second;
                if(visited[next]==false&&mid<=w)
                {
                    q.push(next);
                    visited[next]=true;
                }
            }
        }
        if(chk)
        {
            answer=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    cout << answer;
}

