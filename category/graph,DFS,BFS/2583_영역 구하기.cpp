#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
int M, N, K;
bool Map[101][101];
bool check[101][101];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<int> v;
int msize=1;

void dfs(int x, int y)
{
    check[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M&&!Map[nx][ny]&&!check[nx][ny])
        {
            dfs(nx,ny);
            msize++;
        }
    }
}

int main()
{
    int cnt=0;
    cin >> M >> N >>K;
    for(int i=1;i<=K;i++)
    {
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;
        for(int j=l_x;j<r_x;j++)
        {
            for(int k=l_y;k<r_y;k++)
            {
                Map[j][k]=true;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(check[i][j]==false&&Map[i][j]==false)
            {
                msize=1;
                cnt++;
                dfs(i,j);
                v.push_back(msize);
            }
        }
    }
    sort(v.begin(),v.end());
    cout << cnt << '\n';
    for(int i=0;i<v.size();i++)
    cout << v[i] << " ";
}
