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

bool check[1000002];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long Min, Max; cin >> Min >> Max;
    
    for(long long i=2;i*i<=Max;i++)
    {
        long long j=i*i;
        long long x=j;
        if(Min>j)
            x=(Min/j)*j;
        for(long long k=x;k<=Max;k+=j)
        {
            if(k-Min>=0)
                check[k-Min+1]=true;
        }
    }
    
    int cnt=0;
    for(int i=1;i<=Max-Min+1;i++)
    {
        if(check[i]==false)
            cnt++;
    }
    cout << cnt;
}

