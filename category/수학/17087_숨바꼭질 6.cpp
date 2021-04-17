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

using namespace ::std;

int GCD(int x, int y)
{
    if(y==0)
        return x;
    return GCD(y,x%y);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, S;   cin >> N >> S;
    int t;
    cin >> t;
    t=abs(t-S);
    for(int i=1;i<N;i++)
    {
        int x; cin >> x;
        t=GCD(t,abs(x-S));
    }
    cout << t;
    
}
