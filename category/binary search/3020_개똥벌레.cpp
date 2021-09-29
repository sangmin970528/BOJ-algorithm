#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, height, cnt, ans=0x3f3f3f3f;
vector <int> top,bottom; //종유석, 석순
int main(){
    cin >> n >> height;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i%2==0) bottom.push_back(x);
        else top.push_back(x);
    }

    sort(bottom.begin(),bottom.end());
    sort(top.begin(),top.end());

    for(int i = 1; i <= height; i++){
        int idx = bottom.size() - (lower_bound(bottom.begin(),bottom.end(),i) - bottom.begin());
        int idx2 = top.size() - (upper_bound(top.begin(),top.end(),height-i) - top.begin());
        ans = min(ans,idx + idx2);
    }
    for(int i = 1; i <= height; i++){
        int idx = bottom.size() - (lower_bound(bottom.begin(),bottom.end(),i) - bottom.begin());
        int idx2 = top.size() - (upper_bound(top.begin(),top.end(),height-i) - top.begin());
        if(idx+idx2 == ans) cnt++;
    }

    cout << ans << ' ' << cnt << '\n';
}



