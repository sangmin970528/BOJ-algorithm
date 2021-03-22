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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;  cin >> n;
    set<string> s;
    for(int i=1;i<=n;i++)
    {
        string name;
        string status;
        cin >> name >> status;
        if(status=="enter")
            s.insert(name);
        else
            s.erase(name);
    }
    for(auto iter=s.rbegin();iter!=s.rend();iter++)
    {
        cout << *iter << " ";
    }
}

