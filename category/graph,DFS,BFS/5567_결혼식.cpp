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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> friends[501];
    for(int i=1;i<=m;i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    queue<pair<int,int>> q;
    bool chk[501]={0};
    q.push({1,0});
    chk[1]=true;
    set<int> s;
    while(!q.empty())
    {
        int me=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if (cnt==2)
            continue;
        for(int i=0;i<friends[me].size();i++)
        {
            int next=friends[me][i];
            if(chk[next]==false){
                q.push({next,cnt+1});
                s.insert(next);
                chk[next]=true;
            }
        }
    }
    cout << s.size();
}
