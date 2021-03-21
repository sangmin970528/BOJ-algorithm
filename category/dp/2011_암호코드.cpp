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
    int dp[5001]={0};
    string str;
    getline(cin,str);
    if(str=="\n")
    {
        cout << 0;
        return 0;
    }
    long long n=str.size();
    vector<int> cord(n+1);
    for(int i=0;i<n;i++)
        cord[i+1]=str[i]-'0';
    if(cord[1]==0)
    {
        cout << 0;
        return 0;
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(cord[i]==0)
        {
            if(cord[i-1]>2||cord[i-1]==0)
            {
                cout << 0;
                return 0;
            }else if(cord[i-1]<=2){
                dp[i]=dp[i-2];
                continue;
            }
        }
        if(cord[i-1]==0)
            dp[i]=dp[i-1];
        if(cord[i-1]==1)
        {
            dp[i]=(dp[i-1]+dp[i-2])%1000000;
        }
        if(cord[i-1]==2&&cord[i]<=6)
        {
            dp[i]=(dp[i-1]+dp[i-2])%1000000;
        }
        if(cord[i-1]==2&&cord[i]>6)
        {
            dp[i]=dp[i-1];
        }
        if(cord[i-1]>2)
            dp[i]=dp[i-1];
    }
    cout << dp[n];

    
}

