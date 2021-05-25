#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct magic_info{
    int d;
    int s;
};

int map[50][50];
int dx[]={0,-1,1,0,0};
int dy[]={0,0,0,-1,1};

int ddx[]={0,-1,0,1};
int ddy[]={1,0,-1,0};

vector<magic_info> magic;

int main(){
    int N, M; cin >> N >> M;
    int d,s;
    int shark_loca=(N+1)/2;
    int real_ccnt[4]={0};
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> map[i][j];
        }
    }
    for(int j=1;j<=M;j++)
    {
        cin >> d >> s;
        magic.push_back({d,s});
    }
    for(int i=0;i<magic.size();i++)
    {
        int dir=magic[i].d;
        int size=magic[i].s;
        for(int i=1;i<=size;i++)
        {
            int nx=shark_loca+i*dx[dir];
            int ny=shark_loca+i*dy[dir];
            map[nx][ny]=0;
        }
        // 오른쪽 위쪽 왼쪽 아래쪽
        //빈 공간 채우는 작업
        {
            queue<int> q;
            {
                int x=shark_loca+1;
                int y=shark_loca-1;
                int ddir = 0;
                int cnt=2;
                int t=0;
                bool chk=false;
                if(map[shark_loca][shark_loca-1]!=0)
                {
                    q.push(map[shark_loca][shark_loca-1]);
                    map[shark_loca][shark_loca-1]=0;
                }
                while(cnt!=N)
                {
                    for(int k=1;k<=cnt;k++)
                    {
                        if(map[x][y]!=0)
                        {
                            q.push(map[x][y]);
                            map[x][y]=0;
                        }
                        x+=ddx[ddir];
                        y+=ddy[ddir];
                    }
                    ddir=(ddir+1)%4;
                    t++;
                    if(chk)
                        break;
                    if(t==2){
                        if(cnt+1==N)
                        {
                            chk=true;
                            continue;
                        }
                        cnt++;
                        t=0;
                    }
                }
            }
            {
                bool ccccccchk=false;
                int x=shark_loca+1;
                int y=shark_loca-1;
                int ddir = 0;
                int cnt=2;
                int t=0;
                bool chk=false;
                if(q.empty())
                {
                    ccccccchk=true;
                    break;
                }
                map[shark_loca][shark_loca-1]=q.front();
                q.pop();
                while(cnt!=N)
                {
                    for(int k=1;k<=cnt;k++)
                    {
                        map[x][y]=q.front();
                        q.pop();
                        if(q.empty())
                        {
                            ccccccchk=true;
                            break;
                        }
                        x+=ddx[ddir];
                        y+=ddy[ddir];
                    }
                    if(ccccccchk)
                        break;
                    ddir=(ddir+1)%4;
                    t++;
                    if(chk)
                        break;
                    if(t==2){
                        if(cnt+1==N)
                        {
                            chk=true;
                            continue;
                        }
                        cnt++;
                        t=0;
                    }
                }
            }
        }
        
        while(true)  //한무 폭발
        {
            int ssum=0;
            bool cccchk=true;
            int ccnt[4]={0};
            int current=0;
            vector<vector<pair<int,int>>> locas;
            vector<pair<int,int>> loca;
            int x=shark_loca+1;
            int y=shark_loca-1;
            int ddir = 0;
            int cnt=2;
            int t=0;
            bool chk=false;
            current=map[shark_loca][shark_loca-1];
            ccnt[current]++;
            loca.push_back({shark_loca,shark_loca-1});
            while(cnt!=N)
            {
                for(int k=1;k<=cnt;k++)
                {
                    if(map[x][y]!=current)
                    {
                        if(ccnt[current]>=4)
                        {
                            real_ccnt[current]+=ccnt[current];
                            ssum+=ccnt[current];
                            locas.push_back(loca);
                            loca.clear();
                            ccnt[current]=0;
                            current=map[x][y];
                            ccnt[current]++;
                            loca.push_back({x,y});
                            cccchk=false;
                        }
                        else{
                            loca.clear();
                            ccnt[current]=0;
                            current=map[x][y];
                            ccnt[current]++;
                            loca.push_back({x,y});
                        }
                    }
                    else{
                        ccnt[current]++;
                        loca.push_back({x,y});
                    }
                    x+=ddx[ddir];
                    y+=ddy[ddir];
                }
                ddir=(ddir+1)%4;
                t++;
                if(chk)
                    break;
                if(t==2){
                    if(cnt+1==N)
                    {
                        chk=true;
                        continue;
                    }
                    cnt++;
                    t=0;
                }
            }
            
            for(int m=0;m<locas.size();m++)
            {
                for(int n=0;n<locas[m].size();n++)
                {
                    map[locas[m][n].first][locas[m][n].second]=0;
                }
            }
            //빈 공간 채우는 작업
            {
                queue<int> q;
                {
                    int x=shark_loca+1;
                    int y=shark_loca-1;
                    int ddir = 0;
                    int cnt=2;
                    int t=0;
                    bool chk=false;
                    if(map[shark_loca][shark_loca-1]!=0)
                    {
                        q.push(map[shark_loca][shark_loca-1]);
                        map[shark_loca][shark_loca-1]=0;
                    }
                    while(cnt!=N)
                    {
                        for(int k=1;k<=cnt;k++)
                        {
                            if(map[x][y]!=0)
                            {
                                q.push(map[x][y]);
                                map[x][y]=0;
                            }
                            x+=ddx[ddir];
                            y+=ddy[ddir];
                        }
                        ddir=(ddir+1)%4;
                        t++;
                        if(chk)
                            break;
                        if(t==2){
                            if(cnt+1==N)
                            {
                                chk=true;
                                continue;
                            }
                            cnt++;
                            t=0;
                        }
                    }
                }
                {
                    bool ccccccchk=false;
                    int x=shark_loca+1;
                    int y=shark_loca-1;
                    int ddir = 0;
                    int cnt=2;
                    int t=0;
                    bool chk=false;
                    if(q.empty())
                    {
                        ccccccchk=true;
                        break;
                    }
                    map[shark_loca][shark_loca-1]=q.front();
                    q.pop();
                    while(cnt!=N)
                    {
                        for(int k=1;k<=cnt;k++)
                        {
                            map[x][y]=q.front();
                            q.pop();
                            if(q.empty())
                            {
                                ccccccchk=true;
                                break;
                            }
                            x+=ddx[ddir];
                            y+=ddy[ddir];
                        }
                        if(ccccccchk)
                            break;
                        ddir=(ddir+1)%4;
                        t++;
                        if(chk)
                            break;
                        if(t==2){
                            if(cnt+1==N)
                            {
                                chk=true;
                                continue;
                            }
                            cnt++;
                            t=0;
                        }
                    }
                }
            }
            if(cccchk)
                break;
        }
        queue<int> numbers;
        {
            int ccnt[4]={0};
            int current=0;
            int x=shark_loca+1;
            int y=shark_loca-1;
            int ddir = 0;
            int cnt=2;
            int t=0;
            bool chk=false;
            current=map[shark_loca][shark_loca-1];
            ccnt[current]++;
            while(cnt!=N)
            {
                for(int k=1;k<=cnt;k++)
                {
                    if(map[x][y]!=current)
                    {
                        numbers.push(ccnt[current]);
                        numbers.push(current);
                        current=map[x][y];
                        ccnt[current]=1;
                    }
                    else{
                        ccnt[current]++;
                    }
                    x+=ddx[ddir];
                    y+=ddy[ddir];
                }
                ddir=(ddir+1)%4;
                t++;
                if(chk)
                    break;
                if(t==2){
                    if(cnt+1==N)
                    {
                        chk=true;
                        continue;
                    }
                    cnt++;
                    t=0;
                }
            }
        }
        
        {
            bool ccccccchk=false;
            int x=shark_loca+1;
            int y=shark_loca-1;
            int ddir = 0;
            int cnt=2;
            int t=0;
            bool chk=false;
            if(numbers.empty())
            {
                ccccccchk=true;
                break;
            }
            map[shark_loca][shark_loca-1]=numbers.front();
            numbers.pop();
            while(cnt!=N)
            {
                for(int k=1;k<=cnt;k++)
                {
                    map[x][y]=numbers.front();
                    numbers.pop();
                    if(numbers.empty())
                    {
                        ccccccchk=true;
                        break;
                    }
                    x+=ddx[ddir];
                    y+=ddy[ddir];
                }
                if(ccccccchk)
                    break;
                ddir=(ddir+1)%4;
                t++;
                if(chk)
                    break;
                if(t==2){
                    if(cnt+1==N)
                    {
                        chk=true;
                        continue;
                    }
                    cnt++;
                    t=0;
                }
            }
        }
    }
    cout << real_ccnt[1]+real_ccnt[2]*2+real_ccnt[3]*3;
}
