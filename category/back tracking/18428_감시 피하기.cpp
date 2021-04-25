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

char map[7][7];
int N;
bool chk[7][7];
bool check=false;
int st_num;
vector<pair<int,int>> v;

bool 피하기성공(){
    char temp[7][7];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            temp[i][j]=map[i][j];
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].first;
        int y=v[i].second;
        for(int a=x-1;a>=1;a--) //선생 위확인
        {
            if(temp[a][y]=='O')
                break;
            if(temp[a][y]=='S')
                temp[a][y]='X';
        }
        for(int a=x+1;a<=N;a++) //선생 아래확인
        {
            if(temp[a][y]=='O')
                break;
            if(temp[a][y]=='S')
                temp[a][y]='X';
        }
        for(int b=y-1;b>=1;b--) //선생 왼쪽확인
        {
            if(temp[x][b]=='O')
                break;
            if(temp[x][b]=='S')
                temp[x][b]='X';
        }
        for(int b=y+1;b<=N;b++) //선생 오른쪽확인
        {
            if(temp[x][b]=='O')
                break;
            if(temp[x][b]=='S')
                temp[x][b]='X';
        }
    }
    int cnt=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(temp[i][j]=='S')
                cnt++;
    if(cnt==st_num)
        return true;
    return false;
}

void dfs(int x, int y, int l)
{
    if(l==3)
    {
        if(피하기성공())
        {
            cout << "YES";
            exit(0);
        }
        return;
    }
    for(int i=x;i<=N;i++)
    {
        for(int j=y+1;j<=N;j++)
        {
            if(map[i][j]=='X'&&chk[i][j]==false)
            {
                chk[i][j]=true;
                map[i][j]='O';
                dfs(i,j,l+1);
                map[i][j]='X';
                chk[i][j]=false;
            }
        }
        y=0;
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;    //S 학생 T 선생
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
            if(map[i][j]=='T')
                v.push_back({i,j});
            if(map[i][j]=='S')
                st_num++;
        }
    }
    dfs(1,1,0);
    cout << "NO";
}
