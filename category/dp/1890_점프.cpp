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

int jump[101][101];
long long dp[101][101];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> jump[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(dp[i][j]!=0)
            {
                if(j+jump[i][j]<=N&&jump[i][j]!=0)
                    dp[i][j+jump[i][j]]+=dp[i][j];
                if(i+jump[i][j]<=N&&jump[i][j]!=0)
                    dp[i+jump[i][j]][j]+=dp[i][j];
            }
        }
    }
    cout << dp[N][N];
}
