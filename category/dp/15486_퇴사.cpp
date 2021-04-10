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

int dp[1500001];
int T[1500001];
int P[1500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> T[i] >> P[i];
    }
    int c_max=0;
    for(int i=1;i<=N+1;i++){
        c_max=max(c_max,dp[i]);
        if(i+T[i]-1<=N)
            dp[i+T[i]]=max(c_max+P[i],dp[i+T[i]]);
    }
    cout << c_max << " ";
}
