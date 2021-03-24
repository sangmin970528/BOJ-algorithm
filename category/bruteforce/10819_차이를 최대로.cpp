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

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin >> a[i];
    sort(a.begin(),a.end());
    int max=0;
    do{
        int sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum+=abs(a[i]-a[i+1]);
        }
        if(max<sum)
            max=sum;
    }while(next_permutation(a.begin(), a.end()));
    cout << max;
}
