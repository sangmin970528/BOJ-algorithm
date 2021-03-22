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

int n;
int T[16]={0};
int P[16]={0};
int Max=0;

void find_max(int x, int sum)
{
    if(x==n+1||x==n)
    {
        if(x==n&&T[x]==1)
            sum+=P[x];
        if(Max<sum)
            Max=sum;
        return;
    }
    if(x+T[x]<=n+1)
        find_max(x+T[x],sum+P[x]);
    if(x+1<=n)
        find_max(x+1, sum);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> T[i] >> P[i];
    }
    find_max(1,0);
    cout << Max;
}

