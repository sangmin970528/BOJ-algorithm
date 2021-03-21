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
    int n;  cin >> n;
    vector<int> A(n+1);
    vector<int> dp1(n+1);
    vector<int> dp2(n+1);
    for(int i=1;i<=n;i++)
    cin >> A[i];
    for(int i=1;i<=n;i++)
    {
        dp1[i]=1;
        for(int j=1;j<i;j++)
        {
            if(A[i]>A[j]&&dp1[i]<dp1[j]+1)
            {
                dp1[i]=dp1[j]+1;
            }
        }
    }
    reverse(A.begin()+1, A.end());
    for(int i=1;i<=n;i++)
    {
        dp2[i]=1;
        for(int j=1;j<i;j++)
        {
            if(A[i]>A[j]&&dp2[i]<dp2[j]+1)
            {
                dp2[i]=dp2[j]+1;
            }
        }
    }
    int max=0;
    for(int i=1;i<=n;i++)
    {
        if(max<dp1[i]+dp2[n-i+1])
            max=dp1[i]+dp2[n-i+1];
    }
    
    
    cout << max-1;
    
}
