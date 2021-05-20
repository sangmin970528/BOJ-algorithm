#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char puzzle[20][20];

int main(){
    int R, C; cin >> R >> C;
    vector<string> v;
    for(int i=0;i<R;i++)
    {
        while(getchar() != '\n');
        for(int j=0;j<C;j++)
            scanf("%1c",&puzzle[i][j]);
    }
    for(int i=0;i<R;i++)
    {
        string temp="";
        int start=0;
        while(start<=C)
        {
            if(puzzle[i][start]=='#')
                start++;
            else
                break;
        }
        for(int j=start;j<C;j++)
        {
            if(puzzle[i][j]=='#')
                break;
            temp.push_back(puzzle[i][j]);
        }
        if(temp.size()>=2)
            v.push_back(temp);
    }
    for(int j=0;j<C;j++)
    {
        string temp="";
        int start=0;
        while(start<=R)
        {
            if(puzzle[start][j]=='#')
                start++;
            else
                break;
        }
        for(int i=start;i<R;i++)
        {
            if(puzzle[i][j]=='#')
                break;
            temp.push_back(puzzle[i][j]);
        }
        if(temp.size()>=2)
            v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout << v[0];
}
