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
int check[1001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int S; cin >> S;
    queue<tuple<int,int,int>> q;   //이모티콘 개수,시간초, 복사 했으면 복사한 개수 안했으면 0,
    q.push({1,0,0});
    check[1]=1;
    while(!q.empty())
    {
        int nums=get<0>(q.front());
        int time=get<1>(q.front());
        int copy_num=get<2>(q.front());
        q.pop();
        
        if(nums==S)
        {
            cout << time;
            return 0;
        }
        
        for(int i=1;i<=3;i++)
        {
            if(i==1)//화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
                q.push({nums,time+1,nums});
            if(i==2&&copy_num!=0&&nums+copy_num<=1000&&check[nums+copy_num]==0)//클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
                q.push({nums+copy_num,time+1,copy_num});
            if(i==3&&nums-1>=0&&check[nums-1]==0)//화면에 있는 이모티콘 중 하나를 삭제한다.
            {
                q.push({nums-1,time+1,copy_num});
                check[nums-1]=1;
            }
        }
    }
}
