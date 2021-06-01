#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    if(N<=M)
    {
        cout << N;
        return 0;
    }
    long long Max=-1;
    long long Min=10001;
    for(int i=0;i<M;i++)
    {
        long long t; cin >> t;
        v.push_back(t);
        Min=min(Min,t);
        Max=max(Max,t);
    }
    long long start = 0;
    long long end = 60000000000;
    long long time=0;
    while(start<=end)
    {
        long long mid=(start+end)/2;
        long long sum=M;
        for(int i=0;i<v.size();i++)
        {
            sum+=(mid/v[i]);
        }
        if(sum>=N)
        {
            end=mid-1;
            time=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    long long s=M;
    time--;
    for(int i=0;i<v.size();i++)
    {
        s+=time/v[i];
    }
    time++;
    for(int i=0;i<M;i++)
    {
        if(time%v[i]==0) s++;
        if(s==N){
            cout << i+1;
            break;
        }
    }
}
