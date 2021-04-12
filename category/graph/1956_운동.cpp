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

const int INF=999999999;
int vil[401][401];
int dp[401][401];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int V, E; cin >> V >> E;
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            vil[i][j]=INF;
        }
    }
    for(int i=1;i<=E;i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        vil[x][y]=w;
    }
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(vil[i][j]>vil[i][k]+vil[k][j])
                    vil[i][j]=vil[i][k]+vil[k][j];
            }
        }
    }
    int Min=INF;
    for(int i=1;i<=V;i++)
    {
        Min=min(Min,vil[i][i]);
    }
    if(Min==INF)
        cout << -1;
    else
        cout << Min;
}
