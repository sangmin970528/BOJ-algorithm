#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace ::std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    deque<int> dq;
    for(int i=1;i<=M;i++){
        int x; cin >> x;
        dq.push_back(x);
    }
    int cnt=0;
    while(!dq.empty()){
        if(dq.front()==1){
            dq.pop_front();
            N--;
            for(int i=0;i<N;i++)
            dq[i]--;
        }
        else if(dq.front()<=N/2+1){
            for(int i=0;i<N;i++){
                dq[i]--;
                if(dq[i]==0)
                    dq[i]=N;
            }
            cnt++;
        }
        else if(dq.front()>N/2+1){
            for(int i=0;i<N;i++){
                dq[i]++;
                if(dq[i]==N+1)
                    dq[i]=1;
            }
            cnt++;
        }
    }
    cout << cnt;
}
