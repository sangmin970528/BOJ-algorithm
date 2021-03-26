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
int number = 2000000; // 구하고자 하는 소수의 범위
int primeNum[2000001];

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}

bool check_pelindrom(string str)
{
    int size=str.size();
    string str1;
    string str2;
    if(size%2==1)//홀수
    {
        str1=str.substr(0,size/2+1);
        str2=str.substr(size/2,size/2+1);
        reverse(str2.begin(), str2.end());
        if(str1==str2)
            return true;
        else
            return false;
    }
    else//짝수
    {
        str1=str.substr(0,size/2);
        str2=str.substr(size/2,size/2);
        reverse(str2.begin(), str2.end());
        if(str1==str2)
            return true;
        else
            return false;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    primeNumberSieve();
    for(int i=n;true;i++)
    {
        if(primeNum[i]!=0&&check_pelindrom(to_string(i)))
        {
            cout << i;
            return 0;
        }
    }
    
}

