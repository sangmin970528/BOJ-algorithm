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

int A[201];
int B[201];
bool robot1[201];
bool robot2[201];
int N, K;

int count_zero_B(){
    int cnt=0;
    for(int i=1;i<=2*N;i++)
    {
        if(B[i]==0)
            cnt++;
    }
    return cnt;
}

int count_zero_A(){
    int cnt=0;
    for(int i=1;i<=2*N;i++)
    {
        if(A[i]==0)
            cnt++;
    }
    return cnt;
}

int main()
{
    cin >> N >> K;
    for(int i=1;i<=2*N;i++)
    cin >> A[i];
    int cnt=1;
    while(true)
    {
        if(cnt%2==1){
            B[1]=A[2*N];
            for(int i=1;i<=2*N-1;i++)
            B[i+1]=A[i];
            
            robot2[1]=robot1[2*N];
            for(int i=1;i<=2*N-1;i++)
            robot2[i+1]=robot1[i];
            
            if(robot2[N]==true)
                robot2[N]=false;
            
            for(int i=N;i>=1;i--)
            {
                if(robot2[i-1]==true&&robot2[i]==false&&B[i]>0)
                {
                    robot2[i-1]=false;
                    robot2[i]=true;
                    B[i]--;
                }
            }
            if(robot2[N]==true)
                robot2[N]=false;
          
            if(robot2[1]==false&&B[1]>0){
                robot2[1]=true;
                B[1]--;
            }
            
            if(count_zero_B()>=K)
                break;
        }
        else{
            A[1]=B[2*N];
            for(int i=1;i<=2*N-1;i++)
            A[i+1]=B[i];
            
            robot1[1]=robot2[2*N];
            for(int i=1;i<=2*N-1;i++)
            robot1[i+1]=robot2[i];
            
            if(robot1[N]==true)
                robot1[N]=false;
            
            for(int i=N;i>=1;i--)
            {
                if(robot1[i-1]==true&&robot1[i]==false&&A[i]>0)
                {
                    robot1[i-1]=false;
                    robot1[i]=true;
                    A[i]--;
                }
            }
            if(robot1[N]==true)
                robot1[N]=false;
          
            if(robot1[1]==false&&A[1]>0){
                robot1[1]=true;
                A[1]--;
            }
            
            if(count_zero_A()>=K)
                break;
        }
        cnt++;
    }
    cout << cnt;
}


