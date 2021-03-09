#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>

using namespace ::std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;  cin >>T;
    while(T--){
        string func;
        cin >> func;
        int n;
        cin >> n;
        string nums;
        cin >> nums;
        deque<string> num_arr(n);
        bool reverse=false;
        
        string tempstr;
        for(int i=1,j=0;i<nums.size();i++)
        {
            if(nums[i]==']')
                break;
            
            if(nums[i]==','){
                j++;
            }
            else{
                num_arr[j].push_back(nums[i]);
            }
        }
        
        int t=0;
        for(int i=0;i<func.size();i++)
        {
            if(func[i]=='R')
            {
                reverse=(!reverse);
            }
            else{
                if(num_arr.empty())
                {
                    cout << "error" << '\n';
                    t=1;
                    break;
                }
                if(reverse){
                    num_arr.pop_back();
                }
                else{
                    num_arr.pop_front();
                }
            }
        }
        if(t==0)
        {
            if(!reverse){
                if(!num_arr.empty()){
                    cout << '[';
                    for(int i=0;i<num_arr.size()-1;i++)
                    cout<<num_arr[i]<<',';
                    cout<<num_arr[num_arr.size()-1]<<']';
                }else{
                    cout<<"[]";
                }
            }else{
                if(!num_arr.empty()){
                    cout << '[';
                    for(int i=num_arr.size()-1;i>0;i--)
                    cout<<num_arr[i]<<',';
                    cout<<num_arr[0]<<']';
                }else{
                    cout<<"[]";
                }
            }
            cout <<'\n';
        }
    }
}
