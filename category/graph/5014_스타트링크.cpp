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

int check[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    queue<int> q;
    q.push(S);
    check[S]=1;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        if(current==G)
        {
            cout << check[current]-1;
            return 0;
        }
        if(U+current<=F&&check[U+current]==0)
        {
            check[U+current]=check[current]+1;
            q.push(U+current);
        }
        if(current-D>=1&&check[current-D]==0)
        {
            check[current-D]=check[current]+1;
            q.push(current-D);
        }
    }
    cout << "use the stairs";
}
