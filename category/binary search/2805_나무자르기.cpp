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

long long tree_length[1000000];
long long N, M;
long long answer=0;

bool possible(long long length){
    long long sum=0;
    for(int i=0;i<N;i++){
        if(tree_length[i]-length>=0)
            sum+=(tree_length[i]-length);
    }
    if(sum>=M)
        return true;
    return false;
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    long long low=0;
    long long high=0;
    for(int i=0;i<N;i++)
    {
        cin >> tree_length[i];
        if(high<tree_length[i])
        high=tree_length[i];
    }
    while(low<=high)
    {
        long long mid = (low+high)/2;
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
