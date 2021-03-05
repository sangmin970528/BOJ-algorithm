#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <limits>

using namespace ::std;
int dp[1001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int sum=0;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
                dp[i]=max(dp[j]+1,dp[i]);
        }
        sum=max(sum,dp[i]);
    }
    cout << sum;
}
