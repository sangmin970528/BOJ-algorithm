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

int house[200000];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, c; cin >> n >> c;
    for(int i=0;i<n;i++)
    cin >> house[i];
    sort(house,house+n);
    int low=0;
    int high=house[n-1]-house[0];
    int answer=0;
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        int cnt=1;
        int first=house[0];
        for(int i=1;i<n;i++)
            if(house[i]-first>=mid){
                first=house[i];
                cnt++;
            }
        if(cnt>=c){
            low=mid+1;
            answer=mid;
        }
        else
            high=mid-1;
    }
    cout << answer;
}
