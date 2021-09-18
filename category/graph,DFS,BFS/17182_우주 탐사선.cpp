#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int T[11][11];
int Min=99999999;
bool visited[11];
vector<int> order;
int N, K;

void backTracking(int cur)
{
    if(order.size()==N-1)
    {
        int sum=T[K][order[0]];
        for(int i=1;i<order.size();i++)
        {
            sum+=T[order[i-1]][order[i]];
        }
        if(sum<Min)
            Min=sum;
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(i!=K&&!visited[i])
        {
            visited[i]=true;
            order.push_back(i);
            backTracking(i);
            order.pop_back();
            visited[i]=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> T[i][j];
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(T[i][j]>T[i][k]+T[k][j])
                    T[i][j]=T[i][k]+T[k][j];
    backTracking(0);
    cout << Min;
}
