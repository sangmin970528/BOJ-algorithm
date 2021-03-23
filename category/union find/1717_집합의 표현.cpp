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

vector<int> parent(1000001);
vector<int> t_rank(1000001);

int find_root(int u)
{
    if(u==parent[u]) return u;
    return parent[u]=find_root(parent[u]);  // parent를 찾아낸 루트로 아예 바꿔 버리면 find 연산 수행시 중복되는 연산을 줄여준다. direct로 root노드에 연결시키므로!!
}
void merge(int u, int v)
{
    u=find_root(u);
    v=find_root(v);
    
    if(u==v)    return;
    
    if(t_rank[u]>t_rank[v])
        swap(u,v);
    
    parent[u]=v;
    
    if(t_rank[u]==t_rank[v])
        ++t_rank[v];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0;i<=n;i++)
    {
        parent[i]=i; //i의 부모노드는 i로 초기화!
    }
    for(int i=1;i<=m;i++)
    {
        int command; cin >> command;
        int a, b; cin >> a >> b;
        if(command==0) //집합 합치기
        {
            merge(a,b);
        }
        else //두원소가 한집합에 포함되어 있는지 확인
        {
            if(find_root(a)==find_root(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}

