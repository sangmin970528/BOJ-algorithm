#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>

using namespace std;

int Map[11][11];
int le[20];
int ri[20];
int ans[2];
int n;

void backtracking(int r, int c, int cnt, int color)
{
    if(c>=n){
        r++;
        if(c%2==0)  c=1;
        else c=0;
    }
    if(r>=n){
        ans[color]=max(ans[color],cnt);
        return;
    }
    if(Map[r][c]&&!le[c-r+n-1]&&!ri[r+c])
    {
        le[c-r+n-1]=ri[r+c]=1;
        backtracking(r, c+2, cnt+1, color);
        le[c-r+n-1]=ri[r+c]=0;
    }
    backtracking(r, c+2, cnt, color);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    backtracking(0,0,0,0);
    backtracking(0,1,0,1);
    cout << ans[0]+ans[1];
}
