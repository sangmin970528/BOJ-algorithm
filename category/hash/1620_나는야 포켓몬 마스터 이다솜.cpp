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

using namespace ::std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;   cin >> N >> M;
    map<string,int> m;
    string names[100001];
    for(int i=1;i<=N;i++)
    {
        string str;
        cin >> str;
        m.insert({str,i});
        names[i]=str;
    }
    for(int i=1;i<=M;i++)
    {
        string q; cin >> q;
        if(q[0]>='A'&&q[0]<='Z'){
            cout << m[q] << '\n';
        }else{
            cout << names[stoi(q)] << '\n';
        }
    }
    
}

