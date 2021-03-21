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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int map[1001][1001]={0};
    int dp[1001][1001]={0};
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin >> map[i][j];
    dp[1][1]=map[1][1];
    dp[1][2]=map[1][2]+dp[1][1];
    dp[2][1]=map[2][1]+dp[1][1];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            dp[i][j]=map[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[N][M];
}
