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

vector<int> s_arr(21);
int N, S;
int cnt=0;

void dfs(int depth,int x,int sum)
{
    if(depth>0&&sum==S)
        cnt++;
    if(depth==N)
        return;
    for(int i=x;i<=N;i++)
    dfs(depth+1,i+1,sum+s_arr[i]);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> S;
    for(int i=1;i<=N;i++)
    cin >> s_arr[i];
    dfs(0,1,0);
    cout << cnt;
}

