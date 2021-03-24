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

vector<int> S(13);
vector<int> temp;
bool check[13];
int k;

void dfs(int 이전, int 깊이)
{
    if(깊이==6)
    {
        for(int i=0;i<6;i++)
        cout << temp[i] << " ";
        cout << '\n';
        return;
    }
    for(int i=0;i<k;i++)
    {
        if(이전<S[i])
        {
            temp.push_back(S[i]);
            dfs(S[i],깊이+1);
            temp.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(true){
        cin >> k;
        S.clear();
        temp.clear();
        if(k==0)
            return 0;
        for(int i=0;i<k;i++)
            cin >> S[i];
        dfs(0,0);
        cout << '\n';
    }
}
