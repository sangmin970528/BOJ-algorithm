#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int structure[501];
vector<int> v[501];
int topology[501];
int dp[501];

int main(){
    int N; cin >> N;
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        int time; cin >> time;
        structure[i]=time;
        while(true)
        {
            int x; cin >> x;
            if(x==-1)
                break;
            v[i].push_back(x);
            topology[i]++;
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(v[i].size()==0)
        {
            q.push(i);
            dp[i]=structure[i];
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]==node)
                {
                    topology[i]--;
                    v[i].erase(v[i].begin()+j);
                    if(topology[i]==0)
                    {
                        q.push(i);
                    }
                    dp[i]=max(dp[node]+structure[i],dp[i]);
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        cout << dp[i] << '\n';
    }
}
