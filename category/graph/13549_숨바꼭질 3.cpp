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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K;   cin >> N >> K;
    deque<pair<int,int>> dq;
    dq.push_front({N,0});
    int check[1000001]={0};
    check[N]=1;
    while(!dq.empty())
    {
        int v=dq.front().first;
        int cnt=dq.front().second;
        dq.pop_front();
        if(v==K)
        {
            cout << cnt <<'\n';
            return 0;
        }
        for(int i=0;i<3;i++)
        {
            if(i==2)
            {
                int x=v-1;
                if(x>=0&&check[x]==0){
                    check[x]=1;
                    dq.push_back({x,cnt+1});
                }
            }
            if(i==1)
            {
                int x=v+1;
                if(x<1000000&&check[x]==0){
                    check[x]=1;
                    dq.push_back({x,cnt+1});
                }
            }
            if(i==0)
            {
                int x=v*2;
                if(x<1000000&&check[x]==0){
                    check[x]=1;
                    dq.push_front({x,cnt});
                }
            }
        }
    }
}
