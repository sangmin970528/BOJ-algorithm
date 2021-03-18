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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K;   cin >> N >> K;
    queue<pair<int,int>> q;
    q.push({N,0});
    int check[100001]={0};
    check[N]=1;
    while(!q.empty())
    {
        int v=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(v==K)
        {
            cout << cnt;
            return 0;
        }
        for(int i=0;i<3;i++)
        {
            if(i==0)
            {
                int x=v-1;
                if(x<=100000&&x>=0&&check[x]==0){
                    check[x]=1;
                    q.push({x,cnt+1});
                }
            }
            if(i==1)
            {
                int x=v+1;
                if(x<=100000&&x>=0&&check[x]==0){
                    check[x]=1;
                    q.push({x,cnt+1});
                }
            }
            if(i==2)
            {
                int x=v*2;
                if(x<=100000&&x>=0&&check[x]==0){
                    check[x]=1;
                    q.push({x,cnt+1});
                }
            }
        }
    }
}
