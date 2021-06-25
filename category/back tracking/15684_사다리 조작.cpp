#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sadari[31][31];
int N, M, H;
bool chk=true;
bool check=false;

void back_tracking(int depth, int current, int start){
    if(depth==H+1)
    {
        if(start!=current)
            chk=false;
        else
            return;
    }
    else{
        if(sadari[depth][current]==1)
            back_tracking(depth+1,current+1,start);
        else if(sadari[depth][current-1]==1)
            back_tracking(depth+1,current-1,start);
        else
            back_tracking(depth+1,current,start);
    }
}

bool visited[31][31];

void bt(int r, int c, int cnt, int n){
    if(cnt==n)
    {
        chk=true;
        for(int i=1;i<=N;i++)
        {
            if(sadari[1][i]==1)
                back_tracking(2,i+1,i);
            else if(sadari[1][i-1]==1)
                back_tracking(2,i-1,i);
            else
                back_tracking(2,i,i);
            if(!chk)
                break;
        }
        if(chk)
        {
            cout << n;
            check=true;
            exit(0);
        }
    }
    else{
        for(int i=r;i<=H;i++)
        {
            for(int j=c;j<N;j++)
            {
                if(sadari[i][j-1]==0&&sadari[i][j+1]==0&&sadari[i][j]==0&&visited[i][j]==false)
                {
                    visited[i][j]=true;
                    sadari[i][j]=1;
                    bt(i,j-1,cnt+1,n);
                    sadari[i][j]=0;
                    visited[i][j]=false;
                }
            }
        }
    }
}
int main(){
    cin >> N >> M >> H;
    for(int i=0;i<M;i++)
    {
        int a, b;
        cin >> a >> b;
        sadari[a][b]=1;
    }
    for(int i=0;i<=3;i++)
    {
        bt(1,1,0,i);
        if(check)
            break;
    }
    cout << -1;
}
