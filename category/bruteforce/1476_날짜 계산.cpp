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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int E,S,M; cin >> E >> S >> M;
    int e=1,s=1,m=1;
    for(int i=1;true;i++)
    {
        if(E==e&&S==s&&M==m)
        {
            cout << i;
            break;
        }
        if(e==15)
            e=1;
        else
            e++;
        if(s==28)
            s=1;
        else
            s++;
        if(m==19)
            m=1;
        else
            m++;
    }
}
