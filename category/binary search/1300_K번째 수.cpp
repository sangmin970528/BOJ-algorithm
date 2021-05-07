#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long N; cin >> N;
    int k; cin >> k;
    long long left=1;
    long long right=N*N;
    long long answer=0;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        long long cnt=0;
        for(int i=1;i<=N;i++)
        {
            cnt+=min(mid/i,N);
        }
        if(cnt>=k)
        {
            answer=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout << answer;
}
