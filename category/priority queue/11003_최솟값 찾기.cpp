#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int A[5000001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, L;
    cin >> N >> L;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<N;i++){
        pq.push({A[i],i});
        while(i>=L-1&&pq.top().second<i-L+1) {
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
}
