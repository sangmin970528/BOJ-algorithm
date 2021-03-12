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

long long lan[10000];
long long K, N;

bool possible(long long length){
    int cnt=0;
    for(int i=0;i<K;i++)
    {
        cnt+=lan[i]/length;
    }
    if(N<=cnt)
        return true;
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> K >> N;
    long long high=0;
    long long low=1;
    long long answer=0;
    for(int i=0;i<K;i++)
    {
        cin >> lan[i];
        if(high<lan[i])
            high=lan[i];
    }
    while(low<=high)
    {
        long long mid=(high+low)/2;
        if(possible(mid))
        {
            if(answer<mid)
                answer=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout << answer;
}
