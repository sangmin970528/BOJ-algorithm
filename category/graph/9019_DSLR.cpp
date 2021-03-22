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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--)
    {
        int A, B; cin >> A >> B;
        int check[10000]={0};
        int cnt=0;
        vector<pair<int,char>> v[10000];
        queue<pair<int,int>> q;
        q.push({A,0});
        while(!q.empty())
        {
            int x=q.front().first;
            cnt=q.front().second;
            int y=x;
            int d1=0,d2=0,d3=0,d4=0;
            q.pop();
            if(x==B)
                break;
            
            d4=y%10;
            y/=10;
            d3=y%10;
            y/=10;
            d2=y%10;
            y/=10;
            d1=y%10;
            
            if(x==0)
            {
                int S=9999;
                q.push({S,cnt+1});
                v[S].push_back({x,'S'});
                check[S]=1;
                continue;
            }
            
            int D=(x*2)%10000;
            int S=x-1;
            int L=((d2 * 10 + d3) * 10 + d4) * 10 + d1;
            int R=((d4 * 10 + d1) * 10 + d2) * 10 + d3;
            
            if(check[D]==0)
            {
                q.push({D,cnt+1});
                v[D].push_back({x,'D'});
                check[D]=1;
            }
            if(check[S]==0)
            {
                q.push({S,cnt+1});
                v[S].push_back({x,'S'});
                check[S]=1;
            }
            if(check[L]==0)
            {
                q.push({L,cnt+1});
                v[L].push_back({x,'L'});
                check[L]=1;
            }
            if(check[R]==0)
            {
                q.push({R,cnt+1});
                v[R].push_back({x,'R'});
                check[R]=1;
            }
        }
        vector<char> vv;
        int x=B;
        for(int i=0; i<cnt ;i++)
        {
            vv.push_back(v[x][0].second);
            x=v[x][0].first;
        }
        for(int i=0;i<vv.size();i++)
        {
            cout << vv[vv.size()-i-1];
        }
        cout << '\n';
    }
    
}

