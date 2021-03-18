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
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int dp[100000][2]={0};
        int score[100000][2]={0};
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> score[j][i];
            }
        }
        dp[0][0]=score[0][0];
        dp[0][1]=score[0][1];
        dp[1][0]=score[1][0]+dp[0][1];
        dp[1][1]=score[1][1]+dp[0][0];
        for(int i=2;i<n;i++)
        {
            dp[i][0]=score[i][0]+max(dp[i-1][1],dp[i-2][1]);
            dp[i][1]=score[i][1]+max(dp[i-1][0],dp[i-2][0]);
        }
        cout << max(dp[n-1][0],dp[n-1][1]) << '\n';
    }
}
