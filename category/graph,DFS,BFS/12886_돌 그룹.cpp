#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1001][1001];

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    queue<tuple<int,int,int>> q;
    vector<int> v;
    sort(v.begin(),v.end());
    q.push({A,B,C});
    while(!q.empty())
    {
        int a=get<0>(q.front());
        int b=get<1>(q.front());
        int c=get<2>(q.front());
        q.pop();
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        if(a==b&&b==c)
        {
            cout << 1;
            return 0;
        }
        sort(v.begin(),v.end());
        if(v[0]!=v[1]&&2*v[0]<=1000&&!visited[2*v[0]][v[1]-v[0]])
        {
            q.push({2*v[0],v[1]-v[0],v[2]});
            visited[2*v[0]][v[1]-v[0]]=true;
        }
        if(v[1]!=v[2]&&2*v[1]<=1000&&!visited[2*v[1]][v[2]-v[1]])
        {
            q.push({v[0],2*v[1],v[2]-v[1]});
            visited[2*v[1]][v[2]-v[1]]=true;
            visited[v[2]-v[1]][2*v[1]]=true;
        }
        if(v[0]!=v[2]&&2*v[0]<=1000&&!visited[2*v[0]][v[2]-v[0]])
        {
            q.push({2*v[0],v[1],v[2]-v[0]});
            visited[2*v[0]][v[2]-v[0]]=true;
            visited[v[2]-v[0]][2*v[0]]=true;
        }
    }
    cout << 0 ;
}
