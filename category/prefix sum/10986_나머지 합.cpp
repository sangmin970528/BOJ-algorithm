#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long arr[1000001];
long long sum[1000001];
long long cnt[1001];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        cin >> arr[i];
    
    for(int i=1;i<=N;i++) {
        sum[i]=(sum[i-1]+arr[i])%M;
        cnt[sum[i]]++;
    }
    long long ans = cnt[0];
    for(int i=0;i<M;i++) {
         ans+=cnt[i]*(cnt[i]-1)/2;
    }
    
    cout << ans;
}



