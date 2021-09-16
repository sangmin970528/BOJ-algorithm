#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M, K;
long long tree[1000000*4];
vector<long long> nums;

long long init(int start, int end, int node) {
    if(start==end) return tree[node] = nums[start];
    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1,end,node*2+1);
}

long long sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left<=start && end <=right) return tree[node];
    
    int mid = (start+end)/2;
    return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}

void update(int start, int end, int node, int index, long long dif) {
    if(index<start || index>end) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        long long x; cin >> x;
        nums.push_back(x);
    }
    int s = (int)nums.size();
    init(0,s-1, 1);
    for(int i=0;i<M+K;i++)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if(a==1)
        {
            long long dif = c-nums[b-1];
            nums[b-1]=c;
            update(0,s-1,1,b-1,dif);
        }
        if(a==2)
        {
            cout << sum(0,s-1,1,b-1,(int)c-1) << '\n';
        }
    }
    
    
}
