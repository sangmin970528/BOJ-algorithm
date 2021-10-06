#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    int answer = 2100000000;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    sort(A.begin(),A.end());
    for(int i=0,j=1;i<A.size()&&j<A.size();)
    {
        if(i==j) {
            j++;
            continue;
        }
        if(abs(A[i]-A[j])>=M) {
            answer=min(answer,abs(A[i]-A[j]));
            i++;
        }
        else
            j++;
    }
    cout << answer;
}

