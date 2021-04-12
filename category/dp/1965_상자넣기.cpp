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

int box[1001];
int dp[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> box[i];
        dp[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(box[i]>box[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int x=0;
    for(int i=1;i<=n;i++)
    x=max(x,dp[i]);
    cout << x;
}
