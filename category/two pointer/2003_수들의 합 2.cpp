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

int arr[10001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    for(int i=1;i<=N;i++)
    cin >> arr[i];
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        int sum=0;
        for(int j=i;j<=N;j++)
        {
            sum+=arr[j];
            if(sum==M)
            {
                cnt++;
                break;
            }
            if(sum>M)
                break;
        }
    }
    cout << cnt;
}
