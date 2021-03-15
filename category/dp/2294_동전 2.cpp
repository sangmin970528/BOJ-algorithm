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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int coins[101];
    int dp[10001];
    int n,k; cin >> n >>k;
    for(int i=1;i<=n;i++)
    cin >> coins[i];
    for(int i=1;i<=k;i++)
    dp[i]=10001;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=coins[i];j<=k;j++)
        {
            dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
    }
    if(dp[k]==10001)
        cout << -1;
    else
        cout <<dp[k];
    
}
