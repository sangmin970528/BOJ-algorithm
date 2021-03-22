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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long dp[201][201]={0};
    long long N, K; cin >> N >> K;
    
    for(int i=1;i<=K;i++){
        dp[i][1]=i;
        dp[i][0]=1;
    }
    
    for(int i=0;i<=N;i++)
        dp[1][i]=1;
    
    if(N==1){
        cout << dp[K][N];
        return 0;
    }
    
    for(int i=2;i<=N;i++)
    {
        for(int j=2;j<=K;j++)
        {
            for(int k=0;k<=i;k++)
            dp[j][i]+=dp[j-1][i-k];
            dp[j][i]%=1000000000;
        }
    }
    
    cout << dp[K][N];
}

