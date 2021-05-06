#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> v;
    long long t_sum=0;
    for(int i=0;i<N;i++)
    {
        long long x; cin >> x;
        t_sum+=x;
        v.push_back(x);
    }
    int M;
    cin >> M;
    if(t_sum<=M)
    {
        cout << *max_element(v.begin(), v.end());
        return 0;
    }
    int left=1;
    int right=M;
    int answer=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        long long sum=0;
        for(int i=0;i<N;i++)
        {
            if(v[i]<mid)
                sum+=v[i];
            else
                sum+=mid;
        }
        if(sum>M)
            right=mid-1;
        else
        {
            answer=mid;
            left=mid+1;
        }
    }
    cout << answer;
    
}
