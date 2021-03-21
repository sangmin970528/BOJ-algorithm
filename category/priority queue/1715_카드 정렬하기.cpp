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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        int x; cin >> x;
        pq.push(x);
    }
    
    if(n==1){
        cout << 0;
        return 0;
    }
    int sum=0;
    int t_sum=0;
    int first=0;
    int second=0;
    while(true)
    {
        first=pq.top();
        pq.pop();
        second=pq.top();
        pq.pop();
        t_sum=first+second;
        sum+=t_sum;
        if(pq.empty())
            break;
        pq.push(t_sum);
    }
    cout << sum;
}
           
