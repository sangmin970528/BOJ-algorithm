#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> v;
int alphabet[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum=0;
    int n; cin >> n;
    vector<string> nums;
    for(int i=0;i<n;i++)
    {
        string x; cin >> x;
        nums.push_back(x);
    }
    for(int i=0;i<nums.size();i++)
    {
        int m=1;
        for(int j=(int)nums[i].size()-1;j>=0;j--)
        {
            alphabet[nums[i][j]-'A']+=m;
            m*=10;
        }
    }
    sort(alphabet,alphabet+26);
    reverse(alphabet, alphabet+26);
    
    for(int i=0,j=9;true;i++)
    {
        if(alphabet[i]==0)
            break;
        sum+=alphabet[i]*j;
        j--;
    }
    cout << sum;
    return 0;
}
