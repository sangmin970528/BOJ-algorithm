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

using namespace std;

int N;
int W[11][11];
vector<int> check(11);
int Min=999999999;

void dfs(int start,int v, int sum , int d)
{
    if(d==N&&W[v][start]!=0)
    {
        sum+=W[v][start];
        if(Min>sum)
            Min=sum;
        return;
    }
    if(d==N)
        return;
    for(int i=1;i<=N;i++)
    {
        if(W[v][i]!=0&&check[i]==0)
        {
            check[i]=true;
            dfs(start,i,sum+W[v][i],d+1);
            check[i]=false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> W[i][j];
    for(int i=1;i<=N;i++)
    {
        check[i]=true;
        dfs(i,i,0,1);
        check.clear();
    }
    cout << Min;
}
