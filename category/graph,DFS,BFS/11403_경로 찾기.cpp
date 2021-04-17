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

int adj[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> adj[i][j];
        }
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(adj[i][k]+adj[k][j]>1)
                    adj[i][j]=1;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}
