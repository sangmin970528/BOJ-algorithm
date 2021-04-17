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
    queue<int> q;
    q.push(N);
    int check[100001]={0};
    check[N]=1;
    bool chk=false;
    int cnt=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        if(v==K&&chk==false)
        {
            cout << check[v]-1 << '\n';
            chk=true;
        }
        if(v==K&&chk==true)
            cnt++;
        for(int i=0;i<3;i++)
        {
            if(i==0)
            {
                int x=v-1;
                if(x<=100000&&x>=0&&(check[x]>check[v]||check[x]==0)){
                    check[x]=check[v]+1;
                    q.push(x);
                }
            }
            if(i==1)
            {
                int x=v+1;
                if(x<=100000&&x>=0&&(check[x]>check[v]||check[x]==0)){
                    check[x]=check[v]+1;
                    q.push(x);
                }
            }
            if(i==2)
            {
                int x=v*2;
                if(x<=100000&&x>=0&&(check[x]>check[v]||check[x]==0)){
                    check[x]=check[v]+1;
                    q.push(x);
                }
            }
        }
    }
    cout << cnt;
}
