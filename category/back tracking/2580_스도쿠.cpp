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

int sudoku[9][9];
vector<pair<int,int>> zeros;

bool check1(int r,int num)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[r][i]==num)
            return false;
    }
    return true;
}

bool check2(int c, int num){
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][c]==num)
            return false;
    }
    return true;
}

bool check3(int r, int c, int num){
    r/=3;
    c/=3;
    for(int i=r*3;i<(r*3)+3;i++)
    {
        for(int j=c*3;j<(c*3)+3;j++)
        {
            if(sudoku[i][j]==num)
                return false;
        }
    }
    return true;
}

bool check(int x, int y, int num){
    return (check1(x,num) && check2(y,num) && check3(x,y,num))? true : false;
}

void dfs(int index){
    if(index==zeros.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
            cout << sudoku[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }
    for(int i=1;i<=9;i++)
    {
        int x=zeros[index].first;
        int y=zeros[index].second;
        if(check(x, y, i)){
            sudoku[x][y]=i;
            dfs(index+1);
            sudoku[x][y]=0;
        }
    }

}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]==0)
                zeros.push_back({i,j});
        }
    }
    dfs(0);
}
