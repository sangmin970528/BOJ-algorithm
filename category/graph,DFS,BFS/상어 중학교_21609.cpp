#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int Map[21][21];
int chk[21][21][6];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int answer=0;

vector<pair<int,int>> locations;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> Map[i][j];
    while(true){
        int Max=0;
        int Max_rainbow=0;
        pair<int,int> standard_block={-1,-1};
        for(int c=0;c<=M;c++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    chk[i][j][c]=-1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int cnt=0;
                int cnt_rainbow=0;
                pair<int,int> temp_standard_block;
                vector<pair<int,int>> temp_v;
                if(Map[i][j]!=-1&&Map[i][j]!=0&&Map[i][j]!=-2&&chk[i][j][Map[i][j]]==-1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    temp_standard_block={i,j};
                    int color=Map[i][j];
                    chk[i][j][Map[i][j]]=color;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        temp_v.push_back({x,y});
                        if(Map[x][y]==0)
                            cnt_rainbow++;
                        if(Map[x][y]!=0&&temp_standard_block.first>=x){
                            if(temp_standard_block.first==x){
                                if(temp_standard_block.second>=y)
                                    temp_standard_block={x,y};
                            }
                            else
                                temp_standard_block={x,y};
                        }
                        cnt++;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&chk[nx][ny][color]==-1&&(Map[nx][ny]==color||Map[nx][ny]==0)){
                                chk[nx][ny][color]=color;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
                if(Max<=cnt){
                    if(Max==cnt){
                        if(Max_rainbow<=cnt_rainbow){
                            if(Max_rainbow==cnt_rainbow){
                                if(standard_block.first<=temp_standard_block.first){
                                    if(standard_block.first==temp_standard_block.first){
                                        if(standard_block.second<=temp_standard_block.second){
                                            standard_block=temp_standard_block;
                                            locations=temp_v;
                                        }
                                    }
                                    else{
                                        standard_block=temp_standard_block;
                                        locations=temp_v;
                                    }
                                }
                            }
                            else{
                                Max_rainbow=cnt_rainbow;
                                locations=temp_v;
                                standard_block=temp_standard_block;
                            }
                        }
                    }
                    else{
                        Max=cnt;
                        locations=temp_v;
                        standard_block=temp_standard_block;
                        Max_rainbow=cnt_rainbow;
                    }
                }
            }
        }
        if(Max==1||Max==0)
            break;
        for(int i=0;i<locations.size();i++)
            Map[locations[i].first][locations[i].second]=-2; //-2면 빈공간 의미
        answer+=Max*Max;
        for(int k=1;k<=N;k++){
            for(int i=2;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(Map[i][j]==-1)
                        continue;
                    if(Map[i][j]==-2&&Map[i-1][j]!=-1&&Map[i-1][j]!=-2)
                    {
                        Map[i][j]=Map[i-1][j];
                        Map[i-1][j]=-2;
                    }
                }
            }
        }
        int temp_Map[21][21];
        for(int j=N, ii=1;j>=1;j--,ii++)
            for(int i=1, jj=1;i<=N;i++,jj++)
                temp_Map[ii][jj]=Map[i][j];
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                Map[i][j]=temp_Map[i][j];
        for(int k=1;k<=N;k++){
            for(int i=2;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(Map[i][j]==-1)
                        continue;
                    if(Map[i][j]==-2&&Map[i-1][j]!=-1&&Map[i-1][j]!=-2)
                    {
                        Map[i][j]=Map[i-1][j];
                        Map[i-1][j]=-2;
                    }
                }
            }
        }
    }
    cout << answer;
}
