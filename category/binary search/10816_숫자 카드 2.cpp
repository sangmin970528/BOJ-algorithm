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

int v[500000];
int N;

int lower_binary(int find, int start, int end){
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(v[mid]>=find)
            end=mid;
        else    start=mid+1;
    }
    return end;
}
int upper_binary(int find, int start, int end){
    int mid;
    while(end>start){
        mid=(start+end)/2;
        if(v[mid]>find)
            end=mid;
        else    start=mid+1;
    }
    return end;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
    }
    sort(v,v+N);
    
    int M; cin >> M;
    for(int i=0;i<M;i++)
    {
        int x; cin >> x;
        int s=lower_binary(x, 0, N-1);
        int l=upper_binary(x, 0, N-1);
        if(v[N-1]==x&&l==N-1)
            l++;
        cout << l-s << " ";
    }
}
