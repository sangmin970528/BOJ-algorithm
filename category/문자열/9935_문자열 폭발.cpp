#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    int b_size=(int)bomb.size();
    string temp;
    for(int i=0;i<str.size();i++)
    {
        temp.push_back(str[i]);
        if(temp.size()>=b_size&&temp.substr(temp.size()-b_size,b_size)==bomb)
            temp.erase(temp.begin()+temp.size()-b_size,temp.end());
    }
    if(temp=="")
        cout << "FRULA";
    else
        cout << temp;
}
