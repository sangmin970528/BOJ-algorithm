#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int map[501][501];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Max=0;
    int N, M;   cin >> N >> M;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
    cin >> map[i][j];
    
    
    
    for(int i=1;i<=N;i++)//ㅡ
    {
        for(int j=1;j<=M-3;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i][j+2]+map[i][j+3])
                Max=map[i][j]+map[i][j+1]+map[i][j+2]+map[i][j+3];
        }
    }
    for(int i=1;i<=N-3;i++)//ㅣ
    {
        for(int j=1;j<=M;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i+2][j]+map[i+3][j])
                Max=map[i][j]+map[i+1][j]+map[i+2][j]+map[i+3][j];
        }
    }
    
    
    
    
    for(int i=1;i<=N-1;i++)//ㅁ
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1])
                Max=map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1];
        }
    }
    
    
    
    
    for(int i=1;i<=N-1;i++)//ㅗ
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j+1]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2])
                Max=map[i][j+1]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
        }
    }
    for(int i=1;i<=N-2;i++)//ㅏ
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i+2][j]+map[i+1][j+1])
                Max=map[i][j]+map[i+1][j]+map[i+2][j]+map[i+1][j+1];
        }
    }
    for(int i=1;i<=N-1;i++)//ㅜ
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1])
                Max=map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1];
        }
    }
    for(int i=1;i<=N-2;i++)//ㅓ
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i+1][j]+map[i+1][j+1]+map[i][j+1]+map[i+2][j+1])
                Max=map[i+1][j]+map[i+1][j+1]+map[i][j+1]+map[i+2][j+1];
        }
    }
    
    
    
    for(int i=1;i<=N-2;i++)//
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1])
                Max=map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1];
        }
    }
    for(int i=1;i<=N-2;i++)//
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j+1]+map[i+1][j+1]+map[i+1][j]+map[i+2][j])
                Max=map[i][j+1]+map[i+1][j+1]+map[i+1][j]+map[i+2][j];
        }
    }
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2])
                Max=map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2];
        }
    }
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i+1][j]+map[i+1][j+1]+map[i][j+1]+map[i][j+2])
                Max=map[i+1][j]+map[i+1][j+1]+map[i][j+1]+map[i][j+2];
        }
    }
    
    
    
    
    for(int i=1;i<=N-2;i++)//L
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i+2][j]+map[i+2][j+1])
                Max=map[i][j]+map[i+1][j]+map[i+2][j]+map[i+2][j+1];
        }
    }
    for(int i=1;i<=N-2;i++)//L대칭
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j+1]+map[i+1][j+1]+map[i+2][j+1]+map[i+2][j])
                Max=map[i][j+1]+map[i+1][j+1]+map[i+2][j+1]+map[i+2][j];
        }
    }
    for(int i=1;i<=N-2;i++)//ㄱ
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+2][j+1])
                Max=map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+2][j+1];
        }
    }
    for(int i=1;i<=N-2;i++)//ㄱ대칭
    {
        for(int j=1;j<=M-1;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i+1][j]+map[i+2][j])
                Max=map[i][j]+map[i][j+1]+map[i+1][j]+map[i+2][j];
        }
    }
    
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+2])
                Max=map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+2];
        }
    }
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j])
                Max=map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j];
        }
    }
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2])
                Max=map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
        }
    }
    for(int i=1;i<=N-1;i++)//
    {
        for(int j=1;j<=M-2;j++)
        {
            if(Max<map[i][j+2]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2])
                Max=map[i][j+2]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
        }
    }
    
    cout << Max;
}
