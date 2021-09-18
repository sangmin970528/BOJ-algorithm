#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int x=1;true;x++)
    {
        int Max=-999999999;
        int map[410][810]={0};
        int sum[410][810]={0};
        int ssum=0;
        int N; cin >> N;
        if(N==0)
            return 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=2*(i-1)+1;j++){
                cin >> map[i][j];
                sum[i][j]+=map[i][j]+ssum;
                if(j==2*(i-1)+1)
                    sum[i+1][0]=sum[i][j];
                ssum=sum[i][j];
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=2*(i-1)+1;j++){
                if(j%2==1) {
                    int s=map[i][j];
                    for(int k=1;true;k++) {
                        if(i+k<=N&&k*2+j<=2*(i+k)+1)
                        {
                            if(s>Max)
                                Max=s;
                            s+=sum[i+k][j+2*k]-sum[i+k][j-1];
                        }
                        else {
                            if(s>Max)
                                Max=s;
                            break;
                        }
                    }
                }
                else {
                    int s=map[i][j];
                    for(int k=1;true;k++) {
                        if(i-k>=3&&j-2*k>=2&&j<=2*(i-k)-2)
                        {
                            if(s>Max)
                                Max=s;
                            s+=sum[i-k][j]-sum[i-k][j-2*k-1];
                        }
                        else{
                            if(s>Max)
                                Max=s;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d. %d\n",x,Max);
    }
}
