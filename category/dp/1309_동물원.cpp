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
#include <unordered_set>

using namespace std;

int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    dp[1]=3;
    dp[2]=7;
    for(int i=3;i<=N;i++)
    {
        dp[i]=(dp[i-2]+dp[i-1]*2)%9901;
    }
    cout << dp[N];
}
