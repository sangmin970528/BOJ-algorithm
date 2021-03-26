#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <map>
#include <set>

using namespace std;

int n;
string str;

bool check_good(unsigned long size)
{
    int l=size/2;
    for(int i=2;i<=l;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(str.substr(j,i)==str.substr(j+i,i))
                return false;
        }
    }
    return true;
}

void bt(int d,int pre_num)
{
    if(d==n)
    {
        cout << str;
        exit(0);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(pre_num!=i)
        {
            str.push_back(i+'0');
            if(check_good(str.size()))
                bt(d+1,i);
            str.pop_back();
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    bt(0,0);
}
