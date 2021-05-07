#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> Gate;

int Find(int v)
{
    if(Gate[v]==0)
        return v;
    else
        return Gate[v]=Find(Gate[v]);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int G;  cin >> G;
    int P;  cin >> P;
    int cnt=0;
    for(int i=0;i<P;i++)
    {
        int gate;   cin >> gate;
        if(Gate[gate]==0)
        {
            cnt++;
            if(gate==1)
                Gate[gate]=-1;
            else
                Gate[gate]=Find(gate-1);
        }
        else{
            int next=Find(gate);
            if(next!=-1)
            {
                if(next>1)
                {
                    cnt++;
                    Gate[next]=Find(next-1);
                }
                else if(next==1)
                {
                    cnt++;
                    Gate[next]=-1;
                }
                else
                    break;
            }
            else
                break;
        }
    }
    cout << cnt;
}
