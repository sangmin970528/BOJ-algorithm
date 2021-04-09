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
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int,int>> l;
    while(N--)
    {
        int a,b; cin >> a >> b;
        l.push_back({a,b});
    }
    sort(l.begin(),l.end());
    vector<int> sum;
    int left=l[0].first;
    int right=l[0].second;
    sum.push_back(l[0].second-l[0].first);
    for(int i=1;i<l.size();i++)
    {
        if(l[i].first>right){
            sum.push_back(l[i].second-l[i].first);
            right=l[i].second;
            left=l[i].first;
        }
        else{
            if(right>l[i].second)
                continue;
            sum.back()=l[i].second-left;
            right=l[i].second;
        }
            
    }
    int real_sum=0;
    for(int i=0;i<sum.size();i++)
    real_sum+=sum[i];
    cout << real_sum;
}
