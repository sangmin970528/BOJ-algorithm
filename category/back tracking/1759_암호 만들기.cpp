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

using namespace ::std;

int L, C;
vector<char> c(16);
vector<char> temp;
bool check[16];


void dfs(char x,int cnt)
{
    if(cnt==L)
    {
        int 자음개수=0;
        int 모음개수=0;
        for(int i=0;i<L;i++)
        {
            if(temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u')
                모음개수++;
            else
                자음개수++;
        }
        if(모음개수>=1&&자음개수>=2){
            for(int i=0;i<L;i++)
            cout << temp[i];
            cout << '\n';
        }
        return;
    }
    for(int i=1;i<=C;i++)
    {
        if(check[i]==false&&x<c[i])
        {
            check[i]=true;
            temp.push_back(c[i]);
            dfs(c[i],cnt+1);
            temp.pop_back();
            check[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> L >> C;
    for(int i=1;i<=C;i++)
        cin >> c[i];
    sort(c.begin(),c.begin()+C+1);
    dfs('a'-1,0);
}

