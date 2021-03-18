#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>

using namespace ::std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<tuple<int,int,int,vector<int>>> ball(N+1);
    for(int i=1;i<=N;i++)
    {
        int C, S; cin >> C >> S;
        get<0>(ball[i])=S;
        get<1>(ball[i])=C;
        get<2>(ball[i])=i;
    }
    sort(ball.begin(),ball.end());
    int sum=0;
    int colorsum[200001]={0};
    int ans[200001]={0};
    for(int i=1, j=1;i<=N;i++)
    {
        int size=get<0>(ball[i]);
        int color=get<1>(ball[i]);
        int index=get<2>(ball[i]);
        while(size>get<0>(ball[j]))
        {
            sum+=get<0>(ball[j]);
            colorsum[get<1>(ball[j])]+=get<0>(ball[j]);
            j++;
        }
        ans[index]=sum-colorsum[color];
    }
    for(int i=1;i<=N;i++)
    cout << ans[i] <<'\n';
}
