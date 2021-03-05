#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <limits>

using namespace ::std;

int nums[1001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int cnt=0;
    vector<int> v;
    cin >> n;
    for(int i=1;i<=99;i++)
        nums[i]=1;
    for(int i=100;i<1000;i++)
    {
        v.clear();
        int x=i;
        while(x!=0)
        {
            v.push_back(x%10);
            x/=10;
        }
        if(v[0]-v[1]==v[1]-v[2])
            nums[i]=1;
    }
    for(int i=1;i<=n;i++)
        if(nums[i]==1)
            cnt++;
    cout << cnt;
}
