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

int map[21][21];

int dx[]={0,0,0,-1,1};
int dy[]={0,1,-1,0,0};

int dice[5][4];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> map[i][j];
        }
    }
    x++;
    y++;
    while(K--){
        int k;  cin >> k;  //1부터 동서북남
        int new_dice[5][4]={0};
        if(x+dx[k]>=1&&x+dx[k]<=N&&y+dy[k]>=1&&y+dy[k]<=M) //dice[1][2]북쪽  dice[2][1]서쪽  dice[2][2]맨위 dice[2][3]동쪽  dice[3][2]남쪽  dice[4][2]밑바닥
        {
            x=x+dx[k];
            y=y+dy[k];
            if(k==1)
            {
                new_dice[1][2]=dice[1][2];
                new_dice[2][1]=dice[4][2];
                new_dice[2][2]=dice[2][1];
                new_dice[2][3]=dice[2][2];
                new_dice[3][2]=dice[3][2];
                new_dice[4][2]=dice[2][3];
            }
            if(k==2)
            {
                new_dice[1][2]=dice[1][2];
                new_dice[2][1]=dice[2][2];
                new_dice[2][2]=dice[2][3];
                new_dice[2][3]=dice[4][2];
                new_dice[3][2]=dice[3][2];
                new_dice[4][2]=dice[2][1];
            }
            if(k==3)
            {
                new_dice[1][2]=dice[2][2];
                new_dice[2][1]=dice[2][1];
                new_dice[2][2]=dice[3][2];
                new_dice[2][3]=dice[2][3];
                new_dice[3][2]=dice[4][2];
                new_dice[4][2]=dice[1][2];
            }
            if(k==4)
            {
                new_dice[1][2]=dice[4][2];
                new_dice[2][1]=dice[2][1];
                new_dice[2][2]=dice[1][2];
                new_dice[2][3]=dice[2][3];
                new_dice[3][2]=dice[2][2];
                new_dice[4][2]=dice[3][2];
            }
            
            if(map[x][y]==0)
            {
                map[x][y]=new_dice[4][2];
            }
            else{
                new_dice[4][2]=map[x][y];
                map[x][y]=0;
            }
            
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<4;j++)
                {
                    dice[i][j]=new_dice[i][j];
                }
            }
            cout << dice[2][2] << '\n';
        }
    }
}
