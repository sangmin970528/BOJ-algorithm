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

using namespace ::std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    string str;
    getline(cin, str);
    int first=0;
    bool chk=false;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='<'){
            reverse(str.begin()+first, str.begin()+i);
            chk=true;
        }
        if(str[i]=='>'){
            first=i+1;
            chk=false;
        }
        if(!chk&&str[i]==' ')
        {
            reverse(str.begin()+first, str.begin()+i);
            first=i+1;
        }
        if(!chk&&i==str.size()-1)
        {
            reverse(str.begin()+first, str.end());
        }
    }
    
    cout << str;
}

