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

map<string,string> parent;
map<string, int> t_rank;
map<string, int> cnt;

string find_root(string u)
{
    if(parent[u]==u) return u;
    return parent[u]=find_root(parent[u]);
}

void merge(string u, string v)
{
    u=find_root(u);
    v=find_root(v);
    if(u==v) return;
    
    if (t_rank[u] < t_rank[v]) swap(t_rank[u], t_rank[v]); //always rank[u] >= rank[v]
    parent[v] = u;
    cnt[u] += cnt[v];
    if (t_rank[u] == t_rank[v]) t_rank[u] = t_rank[v] + 1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int F; cin >> F;
        parent.clear();
        t_rank.clear();
        cnt.clear();
        for(int i=1;i<=F;i++)
        {
            string f1, f2;
            cin >> f1 >> f2;
            if(parent[f1]==""){
                t_rank[f1]=0;
                cnt[f1]=1;
                parent[f1]=f1;
            }
            if(parent[f2]==""){
                t_rank[f2]=0;
                cnt[f2]=1;
                parent[f2]=f2;
            }
            merge(f1,f2);
            cout << cnt[find_root(f1)] << '\n';
        }
    }
}

