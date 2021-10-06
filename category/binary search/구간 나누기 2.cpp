#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> li;
int N, M;

bool check(int size) {
    int cnt = 1;
    int mini = li[0];
    int maxi = li[0];
    for(int i=1;i<N;i++) {
        mini = min(mini,li[i]);
        maxi = max(maxi,li[i]);
        if(maxi-mini>size) {
            cnt++;
            mini=li[i];
            maxi=li[i];
        }
    }
    return cnt <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans=0;
    cin >> N >> M;
    int l=0;
    int r=10000;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        li.push_back(x);
    }
    while(l<=r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout << ans;
}

