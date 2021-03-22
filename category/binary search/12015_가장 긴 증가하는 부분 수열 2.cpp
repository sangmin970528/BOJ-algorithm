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

int A[1000001]={0};
int n;
vector<int> lis;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    cin >> A[i];
    for(int i=1;i<=n;i++)
    {
        if(lis.empty()||A[i]>lis.back())
            lis.push_back(A[i]);
        else if(A[i]<lis.back())
        {
            auto iter=lower_bound(lis.begin(), lis.end(), A[i]);
            *iter=A[i];
        }
    }
    cout << lis.size() << '\n';
}

