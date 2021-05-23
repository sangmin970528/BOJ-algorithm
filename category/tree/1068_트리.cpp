#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> node[51];

int main(){
    int N; cin >> N;
    int root;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        if(x==-1)
            root = i;
        else
            node[x].push_back(i);
    }
    int c; cin >> c;
    node[c].clear();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<node[i].size();j++)
        {
            if(node[i][j]==c)
                node[i].erase(node[i].begin()+j);
        }
    }
    if(c==root)
    {
        cout << 0;
        return 0;
    }
    int cnt=0;
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        if(node[n].size()==0)
        {
            cnt++;
            continue;
        }
        for(int i=0;i<node[n].size();i++)
        {
            q.push(node[n][i]);
        }
    }
    cout << cnt;
}
