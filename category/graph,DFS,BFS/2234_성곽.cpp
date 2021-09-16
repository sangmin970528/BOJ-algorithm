#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n, m;
int map[51][51];
bool visited[51][51];
int room_cnt=0;
int room_size=0;
int max_room_size=-1;
int Max=-1;

void dfs(int x, int y)
{
    visited[x][y]=true;
    room_size++;
    if((map[x][y]&1)==0)
    {
        if(!visited[x][y-1])
            dfs(x,y-1);
    }
    if((map[x][y]&1<<1)==0)
    {
        if(!visited[x-1][y])
            dfs(x-1,y);
    }
    if((map[x][y]&1<<2)==0)
    {
        if(!visited[x][y+1])
            dfs(x,y+1);
    }
    if((map[x][y]&1<<3)==0)
    {
        if(!visited[x+1][y])
            dfs(x+1,y);
    }
}

void free(){
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            visited[i][j]=false;
    room_size=0;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> map[i][j];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            room_size=0;
            if(!visited[i][j])
            {
                dfs(i, j);
                if(max_room_size<room_size)
                    max_room_size=room_size;
                room_cnt++;
            }
        }
    }
    
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++){
            if(map[x][y]&1)
            {
                free();
                if(y-1>=0)
                {
                    map[x][y]-=1;
                    dfs(x,y);
                    map[x][y]+=1;
                }
                if(room_size>Max)
                    Max=room_size;
            }
            if(map[x][y]&1<<1)
            {
                free();
                if(x-1>=0)
                {
                    map[x][y]-=2;
                    dfs(x,y);
                    map[x][y]+=2;
                }
                if(room_size>Max)
                    Max=room_size;
            }
            if(map[x][y]&1<<2)
            {
                free();
                if(y+1<n)
                {
                    map[x][y]-=4;
                    dfs(x,y);
                    map[x][y]+=4;
                }
                if(room_size>Max)
                    Max=room_size;
            }
            if(map[x][y]&1<<3)
            {
                free();
                if(x+1<m)
                {
                    map[x][y]-=8;
                    dfs(x,y);
                    map[x][y]+=8;
                }
                if(room_size>Max)
                    Max=room_size;
            }
        }
    }
    
    cout << room_cnt << '\n' << max_room_size << '\n' << Max;
}
