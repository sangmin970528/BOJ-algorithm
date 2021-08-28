#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int dx[] = {0,0,-1,1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};
int A[11][11];
vector<int> tree[11][11];
int food[11][11];
int deadTree[11][11];

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> A[i][j];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            food[i][j]=5;
    for(int i=1;i<=M;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    while(K--)
    {
        //봄
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(tree[i][j].size()==0)
                    continue;
                sort(tree[i][j].begin(),tree[i][j].end());
                for(int k=0;k<tree[i][j].size();k++)
                {
                    if(tree[i][j][k]>food[i][j])
                    {
                        deadTree[i][j]+=tree[i][j][k]/2;
                        tree[i][j][k]=0;
                    }
                    else if(tree[i][j][k]<=food[i][j])
                    {
                        food[i][j]-=tree[i][j][k];
                        tree[i][j][k]++;
                    }
                }
                int loca=-1;
                for(int k=0;k<tree[i][j].size();k++)
                {
                    if(tree[i][j][k]==0){
                        loca=k;
                        break;
                    }
                }
                if(loca!=-1)
                    tree[i][j].erase(tree[i][j].begin()+loca, tree[i][j].end());
            }
        }
        //여름
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(deadTree[i][j]!=0)
                {
                    food[i][j]+=deadTree[i][j];
                    deadTree[i][j]=0;
                }
            }
        }
        //가을
        vector<int> newTree[11][11];
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                newTree[i][j]=tree[i][j];
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(tree[i][j].size()==0)
                    continue;
                for(int k=0;k<tree[i][j].size();k++)
                {
                    if(tree[i][j][k]!=0&&tree[i][j][k]%5==0)
                    {
                        for(int d=0;d<8;d++)
                        {
                            int nx=i+dx[d];
                            int ny=j+dy[d];
                            if(nx>=1&&nx<=N&&ny>=1&&ny<=N)
                                newTree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                tree[i][j]=newTree[i][j];
        //겨울
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                food[i][j]+=A[i][j];
    }
    int answer=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(tree[i][j].size()==0)
                continue;
            answer+=tree[i][j].size();
        }
    }
    cout << answer;
}
