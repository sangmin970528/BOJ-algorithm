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

long long nums[101];
long long dp[101][21];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=1;i<=N;i++)
    cin >> nums[i];
    dp[1][nums[1]]++;
    for(int i=2;i<N;i++)
    {
        for(int j=0;j<=20;j++)
        {
            if(dp[i-1][j]!=0)
            {
                if(j+nums[i]<=20){
                    dp[i][j+nums[i]]+=dp[i-1][j];
                }
                if(j-nums[i]>=0){
                    dp[i][j-nums[i]]+=dp[i-1][j];
                }
            }
        }
    }
    cout << dp[N-1][nums[N]];
}
