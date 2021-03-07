#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <limits>

using namespace ::std;

int tree[27][2];
int N;

void preorder(int n){
    if(n==0) return;
    cout << (char)(n+'A'-1);
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}
void inorder(int n){
    if(n==0) return;
    inorder(tree[n][0]);
    cout << (char)(n+'A'-1);
    inorder(tree[n][1]);
}
void postorder(int n){
    if(n==0) return;
    postorder(tree[n][0]);
    postorder(tree[n][1]);
    cout << (char)(n+'A'-1);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;i++){
        char s, x, y;
        cin >> s >> x >> y;
        if(x>='A'&&x<='Z')
            tree[s-'A'+1][0]=x-'A'+1;
        if(y>='A'&&y<='Z')
            tree[s-'A'+1][1]=y-'A'+1;
    }
    preorder(1); cout << endl;
    inorder(1); cout << endl;
    postorder(1); cout << endl;
}
