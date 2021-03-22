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

int mod=1000000007;
int n;
long long dp[100001][9]={0};


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    dp[1][7]=1;
    dp[1][6]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(j==1)
            {
                dp[i][j]=dp[i-1][2]+dp[i-1][3];
            }
            if(j==2)
            {
                dp[i][j]=dp[i-1][1]+dp[i-1][4];
            }
            if(j==3)
            {
                dp[i][j]=dp[i-1][1]+dp[i-1][4]+dp[i-1][5];
            }
            if(j==4)
            {
                dp[i][j]=dp[i-1][2]+dp[i-1][3]+dp[i-1][6]+dp[i-1][5];
            }
            if(j==5)
            {
                dp[i][j]=dp[i-1][3]+dp[i-1][4]+dp[i-1][6]+dp[i-1][7];
            }
            if(j==6)
            {
                dp[i][j]=dp[i-1][5]+dp[i-1][4]+dp[i-1][8]+dp[i-1][7];
            }
            if(j==7)
            {
                dp[i][j]=dp[i-1][5]+dp[i-1][6]+dp[i-1][8];
            }
            if(j==8)
            {
                dp[i][j]=dp[i-1][6]+dp[i-1][7];
            }
            dp[i][j]%=mod;
        }
    }

}

