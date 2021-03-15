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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    int c[101];
    int d[10001]={0};
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> c[i];
    d[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(c[i]<=j)
                d[j]+=d[j-c[i]];
        }
    }
    cout << d[k];
    
}
