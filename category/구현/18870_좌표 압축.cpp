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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int,int>> v;
    vector<int> ans(N);
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        v.push_back({t,i});
    }
    sort(v.begin(),v.end());
    int temp=1000000001;
    int cnt=-1;
    for(int i=0;i<N;i++)
    {
        if(temp!=v[i].first){
            temp=v[i].first;
            v[i].first=++cnt;
        }
        else
            v[i].first=cnt;
    }
    for(int i=0;i<N;i++)
        ans[v[i].second]=v[i].first;
    for(int i=0;i<N;i++)
    cout << ans[i] <<" ";
}
