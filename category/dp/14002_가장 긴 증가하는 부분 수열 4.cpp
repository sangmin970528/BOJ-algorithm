#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace ::std;

int g[1001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a[1001]={0};
    int dp[1001]={0};
    for(int i=1;i<=n;i++)
    cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                g[i]=j;
            }
        }
    }
    int Max=0;
    int index=0;
    for(int i=1 ; i<=n;i++)
    {
        if(Max<dp[i]){
            Max=dp[i];
            index=i;
        }
    }
    cout << dp[index] << '\n';
    vector<int> v;
    int x=index;
    v.push_back(a[x]);
    for(int i=1;i<dp[index];i++)
    {
        v.push_back(a[g[x]]);
        x=g[x];
    }
    for(int i=0;i<v.size();i++)
    cout << v[v.size()-i-1] << " ";
}

