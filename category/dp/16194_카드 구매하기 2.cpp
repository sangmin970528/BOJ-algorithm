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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    int card[1001]={0};
    int dp[1001]={0};
    for(int i=1;i<=N;i++)
    cin >> card[i];
    dp[1]=card[1];
    
    for(int i=2;i<=N;i++)
    {
        int temp=999999999;
        for(int j=1;j<=i/2;j++)
        {
            if(temp>dp[j]+dp[i-j])
                temp=dp[j]+dp[i-j];
        }
        dp[i]=min(temp,card[i]);
    }
    cout << dp[N];
}
