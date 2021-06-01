#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){  
    int x;
    while(scanf("%d",&x)==1){
        int n; cin >> n;
        x*=10000000;
        vector<int> l;
        for(int i=0;i<n;i++)
        {
            int length;
            cin >> length;
            l.push_back(length);
        }
        sort(l.begin(),l.end());
        int start=0;
        int end=n-1;
        bool chk=false;
        for(int i=start, j=end;i<j;)
        {
            if(l[i]+l[j]==x)
            {
                printf("yes %d %d\n",l[i],l[j]);
                chk=true;
                break;
            }
            if(l[i]+l[j]<x)
                i++;
            else
                j--;
        }
        if(!chk)
            cout << "danger\n";
    }
}
