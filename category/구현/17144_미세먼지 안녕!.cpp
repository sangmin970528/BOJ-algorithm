#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, C, T;
    int A[51][51]={0};
    queue<pair<int,int>> q;
    queue<pair<int,int>> air_cleaner;
    cin >> R >> C >> T;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin >> A[i][j];
            if(A[i][j]!=0&&A[i][j]!=-1)
                q.push({i,j});
            if(A[i][j]==-1)
                air_cleaner.push({i,j});
        }
    }
    int first_air_x=air_cleaner.front().first;
    int first_air_y=air_cleaner.front().second;
    air_cleaner.pop();
    int second_air_x=air_cleaner.front().first;
    int second_air_y=air_cleaner.front().second;
    air_cleaner.pop();
    while(T--){
        int temp_A[51][51]={0};
        temp_A[first_air_x][first_air_y]=-1;
        temp_A[second_air_x][second_air_y]=-1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int cnt=0;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=1&&nx<=R&&ny>=1&&ny<=C&&A[nx][ny]!=-1){
                    temp_A[nx][ny]+=(A[x][y]/5);
                    if(A[x][y]/5>0)
                        cnt++;
                }
            }
            temp_A[x][y]=temp_A[x][y]+A[x][y]-(A[x][y]/5)*cnt;
        }
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                A[i][j]=temp_A[i][j];
        
        int new_A[51][51]={0};
        new_A[first_air_x][first_air_y]=-1;
        new_A[second_air_x][second_air_y]=-1;
        //위 공기청정기
        for(int j=first_air_y+1;j<C;j++) //오른쪽으로
        {
            new_A[first_air_x][j+1]=A[first_air_x][j];
        }
        for(int i=first_air_x;i>1;i--) // 위쪽으로
        {
            new_A[i-1][C]=A[i][C];
        }
        for(int j=C;j>first_air_y;j--) //왼쪽으로
        {
            new_A[1][j-1]=A[1][j];
        }
        for(int i=1;i<first_air_x-1;i++) //아래쪽으로
        {
            new_A[i+1][1]=A[i][1];
        }
        //아래 공기청정기
        for(int j=second_air_y+1;j<C;j++) //오른쪽으로
        {
            new_A[second_air_x][j+1]=A[second_air_x][j];
        }
        for(int i=second_air_x;i<R;i++) //아래쪽으로
        {
            new_A[i+1][C]=A[i][C];
        }
        for(int j=C;j>second_air_y;j--) //왼쪽으로
        {
            new_A[R][j-1]=A[R][j];
        }
        for(int i=R;i>second_air_x+1;i--) // 위쪽으로
        {
            new_A[i-1][1]=A[i][1];
        }
        
        for(int i=1;i<=R;i++)
        {
            for(int j=1;j<=C;j++)
            {
                if(i==1||i==R||i==first_air_x||i==second_air_x||j==1||j==C)
                   A[i][j]=new_A[i][j];
                if(A[i][j]!=0&&A[i][j]!=-1)
                    q.push({i,j});
            }
        }
    }
    int sum=0;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(A[i][j]!=0&&A[i][j]!=-1)
                sum+=A[i][j];
    cout << sum;
}
