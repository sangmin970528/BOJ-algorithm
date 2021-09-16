#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int N, K;
int start_bit = 0;
int Max = -1;
vector<string> words;

void dfs(int depth, int start) {
    if(depth==K)
    {
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            bool chk = true;
            for(int j=0;j<words[i].size();j++)
            {
                if((start_bit&(1<<(words[i][j]-'a')))==0)
                {
                    chk=false;
                    break;
                }
            }
            if(chk)
                cnt++;
        }
        if(Max<cnt)
            Max=cnt;
        return;
    }
    for(int i=start;i<26;i++)
    {
        if((start_bit&(1<<i))==0)
        {
            start_bit |= (1<<i);
            dfs(depth+1,i+1);
            start_bit &= ~(1<<i);
        }
    }
}

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        string x;
        cin >> x;
        words.push_back(x);
    }
    start_bit |= (1<<('a' - 'a'));
    start_bit |= (1<<('n' - 'a'));
    start_bit |= (1<<('t' - 'a'));
    start_bit |= (1<<('i' - 'a'));
    start_bit |= (1<<('c' - 'a'));
    if(K<5)
    {
        cout << 0;
        return 0;
    }
    dfs(5,0);
    cout << Max;
}
