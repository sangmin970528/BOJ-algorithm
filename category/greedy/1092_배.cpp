#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> limit;
vector<int> box;
int limit_max=-1;
int box_max=-1;

bool cmp(int v1, int v2) {
    return v1>v2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        limit.push_back(x);
        limit_max=max(limit_max,x);
    }
    int M; cin >> M;
    for(int i=0;i<M;i++)
    {
        int x; cin >> x;
        box.push_back(x);
        box_max=max(box_max,x);
    }
    if(box_max>limit_max)
    {
        cout <<-1;
        return 0;
    }
    int time=0;
    sort(limit.begin(), limit.end(),cmp);
    sort(box.begin(), box.end(),cmp);
    int ls = (int)limit.size();
    int t=-1;
    for(int i=0,j=0;box.size()!=0;i++,j++)
    {
        t=j;
        if(box[i]>limit[j])
        {
            j--;
            if(i==box.size()-1)
            {
                i=-1;
                j=-1;
                time++;
            }
            continue;
        }
        else
        {
            box.erase(box.begin()+i);
            i=-1;
        }
        if(j==ls-1)
        {
            time++;
            i=-1;
            j=-1;
        }
    }
    if(t!=ls-1)
        time++;
    cout << time;
}
