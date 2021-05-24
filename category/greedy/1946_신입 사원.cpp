#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pair<int,int>> v;
        int cnt=1;
        int min=0;
        for(int i=1;i<=N;i++)
        {
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        min=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if(min>v[i].second){
                cnt++;
                min=v[i].second;
            }
        }
        cout << cnt << '\n';
    }
}
