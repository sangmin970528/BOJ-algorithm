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

using namespace ::std;

vector<int> getPi(string p){
    int m = (int)p.size(), j=0;
    vector<int> pi(m,0);
    for(int i=1;i<m;i++){
        while(j>0&&p[i]!=p[j])
            j=pi[j-1];
        if(p[i]==p[j])
            pi[i]=++j;
    }
    return pi;
}

vector<int> kmp(string s, string p){
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j=0;
    for(int i=0;i<n;i++){
        while(j>0 && s[i]!=p[j])
            j = pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1){
                ans.push_back(i-m+2);
                j=pi[j];
            }else
                j++;
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string T;
    getline(cin,T);
    string P;
    getline(cin,P);
    auto ans=kmp(T,P);
    
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
    
}

