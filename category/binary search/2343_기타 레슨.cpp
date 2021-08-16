#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<long> v;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    
    long l=1;
    long r=1000000000;
    long ans=0;
    while(l<=r){
        long mid=(l+r)/2;
        long sum=0;
        vector<long> sv;
        bool chk=false;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>mid)
            {
                chk=true;
                break;
            }
            if(sum+v[i]<=mid)
                sum+=v[i];
            else
            {
                i--;
                sv.push_back(sum);
                sum=0;
            }
        }
        sv.push_back(sum);
        if(chk){
            l=mid+1;
            continue;
        }
        
        if(sv.size()<=M){
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout << ans;
}
