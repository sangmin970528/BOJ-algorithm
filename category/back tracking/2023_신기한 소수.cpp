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

int n;
string str;
vector<string> v;

bool check_sosu(int x)
{
    if(x==1)
        return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void dfs(int d)
{
    if(d==n)
    {
        v.push_back(str);
        return;
    }
    for(int i=1;i<=9;i++)
    {
        str.push_back(i+'0');
        if(check_sosu(stoi(str)))
        dfs(d+1);
        str.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    dfs(0);
    for(int i=0;i<v.size();i++)
    cout << v[i] << '\n';
}
