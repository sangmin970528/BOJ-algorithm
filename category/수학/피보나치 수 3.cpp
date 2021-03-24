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

using namespace ::std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n; cin >> n;
    int K=1500000;
    int M=1000000;
    int fibo[1500001];
    fibo[0]=0;
    fibo[1]=1;
    
    for(int i=2;i<=K;i++)
    {
        fibo[i]=(fibo[i-1]+fibo[i-2])%M;
    }
    if(n%K==0)
        cout << fibo[0];
    else
    cout << fibo[n%K];
}

